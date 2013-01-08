#include "KeyboardDriver.hpp"
#include "DriverInfo.hpp"
#include "DeviceDriverManagerProxy.hpp"
#include "Service.hpp"

#include <cerrno>
#include <unistd.h>

using namespace SymbolX;

static char const NAME[] = "KeyboardDriverTests";
static const unsigned BUFFER_SIZE = 1024;

int main()
{
  FILE *ofile = fopen("/tmp/KeyboardDriverTests.out", "w");
  IDeviceDriverManager *ddm = new DeviceDriverManagerProxy();
  IDriverInfo *info = new DriverInfo();

  int ret = ddm->GetDriverInfo(info, "MockKeyboardDriver");
  if (DDM_RETURN_OK != ret) {
    fprintf(ofile, "DDM returned error: %d\n", ret);
    return ret;
  }

  fprintf(ofile, "Device information:\nName:\t\t\t%s\nBus Owner:\t\t%s\n"
	  "Communication Endpoint:\t%d\n", info->Name().c_str(),
	  info->BusOwner().c_str(), info->CommunicationPort());

  IPCMessageType msg;
  IPCMessage m(&msg);
  id_t port = info->CommunicationPort();

  char buffer[BUFFER_SIZE];
  DeviceBaseMessage base(&msg);
  base.DeviceNumber() = 123;
  base.SetAddress(buffer);
  base.AddressSize() = sizeof(buffer) / sizeof(char);

  DeviceCancelMessage cancelMessage(&msg);
  cancelMessage.CallType() = DEVICE_CANCEL;
  fprintf(ofile, "\nCalling cancel on driver:\tReturn: ");
  ret = cancelMessage.SendAndReceive(port);
  fprintf(ofile, "%d\n", ret);

  DeviceEntranceMessage entranceMessage(&msg);
  entranceMessage.CallType() = DEVICE_OPEN;
  fprintf(ofile, "Calling open on driver:\t\tReturn: ");
  ret = entranceMessage.SendAndReceive(port);
  fprintf(ofile, "%d\n", ret);

  entranceMessage.CallType() = DEVICE_CLOSE;
  fprintf(ofile, "Calling close on driver:\tReturn: ");
  ret = entranceMessage.SendAndReceive(port);
  fprintf(ofile, "%d\n", ret);

  DeviceIOMessage ioMessage(&msg);
  ioMessage.CallType() = DEVICE_READ;
  ioMessage.Offset() = 0;
  ioMessage.Count() = static_cast<int>(sizeof(buffer) / sizeof(char));
  fprintf(ofile, "Calling read on driver:\t\tReturn: ");
  ret = ioMessage.SendAndReceive(port);
  fprintf(ofile, "%d\n\t\t\t\tData: ", ret);
  for (unsigned i = 0; i < BUFFER_SIZE; ++i) {
    fprintf(ofile, "0x%X ", static_cast<unsigned char>(buffer[i]));
  }
  fprintf(ofile, "\n");

  DeviceIOControlMessage ioctlMessage(&msg);
  ioctlMessage.CallType() = DEVICE_IO_CONTROL;
  ioctlMessage.Request() = KEYBOARD_IOCTL_CLEAR_DATA;
  fprintf(ofile, "Calling ioctl on driver:\tReturn: ");
  ret = ioctlMessage.SendAndReceive(port);
  fprintf(ofile, "%d\n", ret);

  ioMessage.CallType() = DEVICE_READ;
  ioMessage.Offset() = 0;
  ioMessage.Count() = static_cast<int>(sizeof(buffer) / sizeof(char));
  fprintf(ofile, "Calling read on driver:\t\tReturn: ");
  ret = ioMessage.SendAndReceive(port);
  fprintf(ofile, "%d\n\t\t\t\tData: ", ret);
  for (unsigned i = 0; i < BUFFER_SIZE; ++i) {
    fprintf(ofile, "0x%X ", static_cast<unsigned char>(buffer[i]));
  }
  fprintf(ofile, "\n");

  ioMessage.CallType() = DEVICE_WRITE;
  ioMessage.Offset() = 0;
  ioMessage.Count() = 1;
  buffer[0] = '0';
  fprintf(ofile, "Calling write on driver:\tReturn: ");
  ret = ioMessage.SendAndReceive(port);
  fprintf(ofile, "%d\n", ret);

  sleep(5);

  ioMessage.CallType() = DEVICE_WRITE;
  ioMessage.Offset() = 0;
  ioMessage.Count() = 1;
  buffer[0] = '1';
  fprintf(ofile, "Calling write on driver:\tReturn: ");
  ret = ioMessage.SendAndReceive(port);
  fprintf(ofile, "%d\n", ret);

  DeviceIOVectorMessage iovMessage(&msg);
  iovMessage.CallType() = DEVICE_GATHER;
  iovMessage.Offset() = 0;
  iovMessage.Count() = 0;
  fprintf(ofile, "Calling gather on driver:\tReturn: ");
  ret = iovMessage.SendAndReceive(port);
  fprintf(ofile, "%d\n", ret);

  iovMessage.CallType() = DEVICE_SCATTER;
  iovMessage.Offset() = 0;
  iovMessage.Count() = 0;
  fprintf(ofile, "Calling scatter on driver:\tReturn: ");
  ret = iovMessage.SendAndReceive(port);
  fprintf(ofile, "%d\n", ret);

  delete ddm;

  delete info;

  if (-1 == fflush(ofile)) {
    Service::Panic((char*)NAME, (char*)strerror(errno), errno);
    return errno;
  }
  if (-1 == fclose(ofile)) {
    Service::Panic((char *)NAME, (char *)strerror(errno), errno);
    return errno;
  }

  // Wait for service to be terminated.
  while (1) {
    sleep(900);
  }

  return 0;
}
