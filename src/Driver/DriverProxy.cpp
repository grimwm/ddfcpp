#include "DriverProxy.hpp"
#include "Service.hpp" // XXX

using namespace SymbolX;

IDriverInfo *DriverProxy::GetDriverInfo() const
{
  return _info;
}

int DriverProxy::Open(const DriverName &name, id_t deviceNumber)
{
  if (_alreadyOpen) {
    return DEVICE_RETURN_PROXY_ALREADY_OPEN;
  }

  int ret = _ddm->GetDriverInfo(_info, name.c_str());
  if (DDM_RETURN_OK != ret) {
    return DEVICE_RETURN_ERROR;
  }

  DeviceEntranceMessage openMessage(_message);
  openMessage.CallType() = DEVICE_OPEN;
  openMessage.DeviceNumber() = deviceNumber;
  ret = openMessage.SendAndReceive(_info->CommunicationPort());
  if (ret) {
    return DEVICE_RETURN_ERROR;
  }

  _alreadyOpen = true;
  _deviceNumber = deviceNumber;

  return openMessage.CallType();
}

int DriverProxy::Close()
{
  DeviceEntranceMessage closeMessage(_message);
  closeMessage.CallType() = DEVICE_CLOSE;
  closeMessage.DeviceNumber() = _deviceNumber;
  int ret = closeMessage.SendAndReceive(_info->CommunicationPort());
  if (ret) {
    return DEVICE_RETURN_ERROR;
  }
  if (DEVICE_RETURN_OK != closeMessage.CallType()) {
    return closeMessage.CallType();
  }

  _alreadyOpen = false;

  return closeMessage.CallType();
}

int DriverProxy::Read(long offset, int count, unsigned char *output)
{
  DeviceIOMessage readMessage(_message);
  readMessage.CallType() = DEVICE_READ;
  readMessage.DeviceNumber() = _deviceNumber;
  readMessage.SetAddress(reinterpret_cast<char*>(output));
  readMessage.Offset() = offset;
  readMessage.Count() = count;
  int ret = readMessage.SendAndReceive(_info->CommunicationPort());
  if (ret) {
    return DEVICE_RETURN_ERROR;
  }
  return readMessage.CallType();
}

int DriverProxy::Write(long offset, int count, unsigned char *input)
{
  DeviceIOMessage writeMessage(_message);
  writeMessage.CallType() = DEVICE_WRITE;
  writeMessage.DeviceNumber() = _deviceNumber;
  writeMessage.SetAddress(reinterpret_cast<char*>(input));
  writeMessage.Offset() = offset;
  writeMessage.Count() = count;
  int ret = writeMessage.SendAndReceive(_info->CommunicationPort());
  if (ret) {
    return DEVICE_RETURN_ERROR;
  }
  return writeMessage.CallType();
}

int DriverProxy::IOControl(int request, unsigned char *argument)
{
  DeviceIOControlMessage ioctlMessage(_message);
  ioctlMessage.CallType() = DEVICE_IO_CONTROL;
  ioctlMessage.DeviceNumber() = _deviceNumber;
  ioctlMessage.SetAddress(reinterpret_cast<char*>(argument));
  ioctlMessage.Request() = request;
  int ret = ioctlMessage.SendAndReceive(_info->CommunicationPort());
  if (ret) {
    SERVICE_LOG("Hit message error in IOControl.\n");
    return DEVICE_RETURN_ERROR;
  }
  return ioctlMessage.CallType();
}

int DriverProxy::Gather(long offset, int count, unsigned char *output)
{
  DeviceIOVectorMessage gatherMessage(_message);
  gatherMessage.CallType() = DEVICE_GATHER;
  gatherMessage.DeviceNumber() = _deviceNumber;
  gatherMessage.SetAddress(reinterpret_cast<char*>(output));
  gatherMessage.Offset() = offset;
  gatherMessage.Count() = count;
  int ret = gatherMessage.SendAndReceive(_info->CommunicationPort());
  if (ret) {
    return DEVICE_RETURN_ERROR;
  }
  return gatherMessage.CallType();
}

int DriverProxy::Scatter(long offset, int count, unsigned char *input)
{
  DeviceIOVectorMessage scatterMessage(_message);
  scatterMessage.CallType() = DEVICE_SCATTER;
  scatterMessage.DeviceNumber() = _deviceNumber;
  scatterMessage.SetAddress(reinterpret_cast<char*>(input));
  scatterMessage.Offset() = offset;
  scatterMessage.Count() = count;
  int ret = scatterMessage.SendAndReceive(_info->CommunicationPort());
  if (ret) {
    return DEVICE_RETURN_ERROR;
  }
  return scatterMessage.CallType();
}

int DriverProxy::Cancel()
{
  DeviceCancelMessage cancelMessage(_message);
  cancelMessage.CallType() = DEVICE_CANCEL;
  cancelMessage.DeviceNumber() = _deviceNumber;
  int ret = cancelMessage.SendAndReceive(_info->CommunicationPort());
  if (ret) {
    return DEVICE_RETURN_ERROR;
  }
  return cancelMessage.CallType();
}
