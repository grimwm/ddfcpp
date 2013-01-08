#include "DeviceDriverManagerProxy.hpp"
#include <memory>

using namespace SymbolX;

int DeviceDriverManagerProxy::_parseCSVIntoStringList(StringList &resultList)
{
  char *cResults = new char[_message.AddressSize()];
  std::auto_ptr<char> driverListMem(cResults);
  _message.SetAddress((char*)cResults);
  int ret = _message.SendAndReceive(ddmFindProcessID());
  if (ret) {
    return DDM_RETURN_ERROR;
  }
  if (DDM_RETURN_OK != _message.CallType()) {
    return _message.CallType();
  }

  std::string results = cResults;
  size_t lhs, rhs;
  for (
       lhs = 0, rhs = results.find_first_of(',');
       std::string::npos != rhs;
       lhs = rhs+1, rhs = results.find_first_of(',', rhs+1)) {
    resultList.push_back(results.substr(lhs, rhs-lhs));
  }
  resultList.push_back(results.substr(lhs, rhs-lhs));

  return _message.CallType();
}

int DeviceDriverManagerProxy::RegisterDriver(const char *name,
					     const char *busOwner)
{
  _message.CallType() = DDM_REGISTER;
  _message.AddressSize() = strlen(name);
  _message.SetAddress((char*)name);
  int ret = _message.SendAndReceive(ddmFindProcessID());
  if (ret) {
    return DDM_RETURN_ERROR;
  }
  if (DDM_NEXT != _message.CallType()) {
    return _message.CallType();
  }

  _message.AddressSize() = strlen(busOwner);
  _message.SetAddress((char*)busOwner);
  ret = _message.SendAndReceive(ddmFindProcessID());
  if (ret) {
    return DDM_RETURN_ERROR;
  }
  return _message.CallType();
}

int DeviceDriverManagerProxy::UnregisterDriver(const char *name)
{
  _message.CallType() = DDM_UNREGISTER;
  _message.AddressSize() = strlen(name);
  _message.SetAddress((char*)name);
  int ret = _message.SendAndReceive(ddmFindProcessID());
  if (ret) {
    return DDM_RETURN_ERROR;
  }
  return _message.CallType();
}

int DeviceDriverManagerProxy::GetDriverInfo(IDriverInfo *info,
					    const char *name)
{
  if (!DriverInfo::RemoteCopy(*info, ddmFindProcessID(), name)) {
    return DDM_RETURN_ERROR;
  }

  return DDM_RETURN_OK;
}

int DeviceDriverManagerProxy::ListBusses(StringList &busses)
{
  _message.CallType() = DDM_ENUMERATE_BUSSES;
  int ret = _message.SendAndReceive(ddmFindProcessID());
  if (ret) {
    return DDM_RETURN_ERROR;
  }
  if (DDM_NEXT != _message.CallType()) {
    return _message.CallType();
  }

  return _parseCSVIntoStringList(busses);
}

int DeviceDriverManagerProxy::ListDrivers(StringList &drivers)
{
  _message.CallType() = DDM_ENUMERATE_DRIVERS;
  int ret = _message.SendAndReceive(ddmFindProcessID());
  if (ret) {
    return DDM_RETURN_ERROR;
  }
  if (DDM_NEXT != _message.CallType()) {
    return _message.CallType();
  }

  return _parseCSVIntoStringList(drivers);
}

int DeviceDriverManagerProxy::ListDriversOnBus(StringList &drivers,
					       const char *busName)
{
  _message.CallType() = DDM_FIND_BUS_INFO;
  _message.AddressSize() = strlen(busName);
  _message.SetAddress((char*)busName);
  int ret = _message.SendAndReceive(ddmFindProcessID());
  if (ret) {
    return DDM_RETURN_ERROR;
  }
  if (DDM_NEXT != _message.CallType()) {
    return _message.CallType();
  }

  return _parseCSVIntoStringList(drivers);
}
