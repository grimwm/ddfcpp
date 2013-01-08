#define _SYSTEM	1

#include <cerrno>
#include <cstdio>

#include <map>
#include <vector>

#include <sys/types.h>

#include "DDMMessage.hpp"
#include "Memory.hpp"
#include "Service.hpp"

#include "DriverInfo.hpp"

using namespace SymbolX;

typedef std::vector<DriverName> DriverNameVector;
typedef std::map<DriverName, IDriverInfo*> DriverMap;
typedef std::map<DriverName, DriverMap*> BusMap;

class DeviceDriverManager
{
private:
  int _exitStatus;
  DriverMap _drivers;
  BusMap _busses;

  inline bool _tellRequiredStorageSize(DDMMessage &msg, unsigned long length)
  {
    msg.CallType() = DDM_NEXT;
    msg.AddressSize() = static_cast<long>(length);
    if (OK != msg.SendAndReceive(msg.Sender())) {
      msg.CallType() = DDM_RETURN_ERROR;
      return false;
    }

    return true;
  }

  inline bool _setDriverName(DriverName &name, DDMMessage &msg)
  {
    long size = msg.AddressSize();
    if (size < 1) {
      msg.CallType() = DDM_RETURN_ERROR;
      return false;
    }

    char cname[size+1];
    if (OK != Memory::Copy(SELF_PROC, reinterpret_cast<long>(cname),
			   msg.Sender(),
			   reinterpret_cast<long>(msg.GetAddress()),
			   msg.AddressSize())) {
      msg.CallType() = DDM_RETURN_ERROR;
    }
    cname[size] = '\0';
    name = cname;
    return true;
  }

  inline bool _sendData(DDMMessage &msg, DriverName data)
  {
    if (!_tellRequiredStorageSize(msg, data.size())) {
      return false;
    }

    if (OK != Memory::Copy(msg.Sender(),
			   reinterpret_cast<long>(msg.GetAddress()),
			   SELF_PROC,
			   reinterpret_cast<long>(data.c_str()),
			   data.size())) {
      msg.CallType() = DDM_RETURN_ERROR;
      return false;
    }

    return true;
  }

  inline bool _enumerateBusMapKeys(DDMMessage &msg,
				   BusMap::const_iterator itBegin,
				   BusMap::const_iterator itEnd)
  {
    DriverName data;
    for (BusMap::const_iterator it = itBegin; itEnd != it; ++it) {
      data += it->first + ",";
    }
    data[data.size()-1] = '\0';

    if (data.size() && !_sendData(msg, data)) {
      return false;
    }

    return true;
  }

  inline bool _enumerateDriverMapValues(DDMMessage &msg,
					DriverMap::const_iterator itBegin,
					DriverMap::const_iterator itEnd)
  {
    DriverName data;
    for (DriverMap::const_iterator it = itBegin; itEnd != it; ++it) {
      data += it->second->Name() + ",";
    }
    data[data.size()-1] = '\0';

    if (data.size() && !_sendData(msg, data)) {
      return false;
    }

    return true;
  }

  inline void _registerDriver(DDMMessage &msg)
  {
    DriverName name;
    if (!_setDriverName(name, msg)) {
      return;
    }

    if (_drivers.end() != _drivers.find(name)) {
      msg.CallType() = DDM_RETURN_ERROR;
      return;
    }

    msg.CallType() = DDM_NEXT;
    if (OK != msg.SendAndReceive(msg.Sender())) {
      msg.CallType() = DDM_RETURN_ERROR;
      return;
    }
    DriverName bus;
    if (!_setDriverName(bus, msg)) {
      return;
    }

    // Lazily allocate memory for bus if necessary.
    if (_busses.end() == _busses.find(bus)) {
      _busses[bus] = new DriverMap;
    }

    DriverMap *busDrivers = _busses[bus];
    IDriverInfo *info = new DriverInfo(msg.Sender(), name, bus);
    _drivers[name] = info;
    (*busDrivers)[name] = info;

    msg.CallType() = DDM_RETURN_OK;
  }

  inline void _unregisterDriver(DDMMessage &msg)
  {
    DriverName name;
    if (!_setDriverName(name, msg)) {
      return;
    }

    DriverMap::iterator driversIter = _drivers.find(name);
    if (_drivers.end() == driversIter) {
      msg.CallType() = DDM_RETURN_ERROR;
      return;
    }

    IDriverInfo *info = driversIter->second;
    BusMap::iterator bussesIter = _busses.find(info->BusOwner());
    DriverMap *busDrivers = bussesIter->second;
    DriverMap::iterator busDriversIter = busDrivers->find(name);
    if (busDrivers->end() == busDriversIter) {
      msg.CallType() = DDM_RETURN_ERROR;
      return;
    }
    delete info;

    _drivers.erase(driversIter);
    busDrivers->erase(busDriversIter);
    if (!busDrivers->size()) {
      delete busDrivers;
      _busses.erase(bussesIter);
    }

    msg.CallType() = DDM_RETURN_OK;
  }

  inline void _findBusInfo(DDMMessage &msg)
  {
    DriverName name;
    if (!_setDriverName(name, msg)) {
      return;
    }

    BusMap::const_iterator busIter = _busses.find(name);
    if (_busses.end() == busIter) {
      msg.CallType() = DDM_RETURN_ERROR;
      return;
    }

    DriverMap *drivers = busIter->second;
    if (!_enumerateDriverMapValues(msg, drivers->begin(), drivers->end())) {
      return;
    }

    msg.CallType() = DDM_RETURN_OK;
  }

  inline void _findDriverInfo(DDMMessage &msg)
  {
    DriverName name;
    if (!_setDriverName(name, msg)) {
      return;
    }

    DriverMap::const_iterator driversIter = _drivers.find(name);
    if (_drivers.end() == driversIter) {
      msg.CallType() = DDM_RETURN_ERROR;
      return;
    }
    IDriverInfo *info = driversIter->second;

    msg.CallType() = DDM_NEXT;
    msg.DriverPort() = info->CommunicationPort();
    msg.AddressSize() = static_cast<long>(info->BusOwner().size()+1);

    if (OK != msg.SendAndReceive(msg.Sender())) {
      msg.CallType() = DDM_RETURN_ERROR;
      return;
    }

    if (OK != Memory::Copy(msg.Sender(),
			   reinterpret_cast<long>(msg.GetAddress()), SELF_PROC,
			   reinterpret_cast<long>(info->BusOwner().c_str()),
			   info->BusOwner().size())) {
      msg.CallType() = DDM_RETURN_ERROR;
      return;
    }

    msg.CallType() = DDM_RETURN_OK;
  }

  inline void _enumerateBusses(DDMMessage &msg)
  {
    if (!_enumerateBusMapKeys(msg, _busses.begin(), _busses.end())) {
      return;
    }

    msg.CallType() = DDM_RETURN_OK;
  }

  inline void _enumerateDrivers(DDMMessage &msg)
  {
    if (!_enumerateDriverMapValues(msg, _drivers.begin(), _drivers.end())) {
      return;
    }

    msg.CallType() = DDM_RETURN_OK;
  }

public:
  inline DeviceDriverManager() :
    _exitStatus(0)
  {
  }

  inline int exitStatus() const
  {
    return _exitStatus;
  }

  inline void run()
  {
    IPCMessageType ipcMsg;
    DDMMessage msg(&ipcMsg);

    while (1) {
      int ret = msg.Receive(ANY_PROC);
      if (OK != ret) {
#ifdef DEBUG
	SERVICE_LOG("DDM: Error receiving packet.\n");
#endif
	continue;
      }

      id_t type = msg.CallType();
      msg.CallType() = DDM_RETURN_OK;
      switch (type) {
      case DDM_REGISTER:
	_registerDriver(msg);
	break;
      case DDM_UNREGISTER:
	_unregisterDriver(msg);
	break;
      case DDM_FIND_BUS_INFO:
	_findBusInfo(msg);
	break;
      case DDM_FIND_DRIVER_INFO:
	_findDriverInfo(msg);
	break;
      case DDM_ENUMERATE_BUSSES:
	_enumerateBusses(msg);
	break;
      case DDM_ENUMERATE_DRIVERS:
	_enumerateDrivers(msg);
	break;
      default:
	msg.CallType() = DDM_RETURN_ERROR;
	break;
      }

      if (DDM_RETURN_FAILED_RESPONSE != msg.CallType()) {
	ret = msg.Send(msg.Sender());
	if (OK != ret) {
#ifdef DEBUG
	  SERVICE_LOG("DDM: Error sending packet.\n");
#endif
	}
      }
      else {
#ifdef DEBUG
	SERVICE_LOG("DDM: Error handling request.\n");
#endif
      }
    }
  }
};

int main()
{
  DeviceDriverManager ddm;
  ddm.run();
  return ddm.exitStatus();
}
