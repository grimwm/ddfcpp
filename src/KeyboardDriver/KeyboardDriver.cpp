#include "KeyboardDriver.hpp"
#include "IO.hpp"
#include "Memory.hpp"
#include "Service.hpp"

using namespace SymbolX;

static const int KEYBOARD_DATA_PORT = 0x60;
static const int KEYBOARD_CMD_PORT = 0x64;

static const int KEYBOARD_DISABLE_KEYBOARD = 0xAD;
static const int KEYBOARD_ENABLE_KEYBOARD = 0xAE;

void KeyboardDriver::Initialize()
{
  memset(_keyboardData, 0, KEYBOARD_DATA_MAX*sizeof(unsigned char));
  id_t irq = KEYBOARD_IRQ;
  _interruptId = irq;
  int ret = IO::InstallInterruptHandler(irq, &_interruptId);
  if (ret) {
    Service::Panic(_name, "error installing interrupt handler", ret);
  }
}

void KeyboardDriver::InterruptHandler(DeviceInterruptMessage &msg)
{
  unsigned long byte = IO::ReadByte(KEYBOARD_DATA_PORT);

  int ret = IO::EnableInterruptHandler(&_interruptId);
  if (ret) {
    Service::Panic(_name, "error enabling interrupt", ret);
  }

  _keyboardData[_dataLocation] = static_cast<unsigned char>(byte);
  _dataLocation = (_dataLocation+1) % KEYBOARD_DATA_MAX;
}

void KeyboardDriver::ReadHandler(DeviceIOMessage &msg)
{
  long offset = msg.Offset();
  int count = msg.Count();

  if (offset < 0 || count < 0 || offset+count > KEYBOARD_DATA_MAX) {
    msg.CallType() = DEVICE_RETURN_ERROR;
    return;
  }

  Memory::Copy(msg.Sender(), reinterpret_cast<long>(msg.GetAddress()),
	       SELF_PROC, reinterpret_cast<long>(_keyboardData)+offset, count);

  msg.CallType() = DEVICE_RETURN_OK;
}

void KeyboardDriver::WriteHandler(DeviceIOMessage &msg)
{
  char byte = '\0';

  Memory::Copy(SELF_PROC, reinterpret_cast<long>(&byte),
	       msg.Sender(), reinterpret_cast<long>(msg.GetAddress()), 1);

  switch (byte) {
  case '1':
    IO::WriteByte(KEYBOARD_CMD_PORT, KEYBOARD_ENABLE_KEYBOARD);
    break;
  case '0':
    IO::WriteByte(KEYBOARD_CMD_PORT, KEYBOARD_DISABLE_KEYBOARD);
    break;
  default:
    msg.CallType() = DEVICE_RETURN_ERROR;
    return;
  }

  msg.CallType() = DEVICE_RETURN_OK;
}

void KeyboardDriver::IOControlHandler(DeviceIOControlMessage &msg)
{
  switch (msg.Request()) {
  case KEYBOARD_IOCTL_CLEAR_DATA:
    memset(_keyboardData, 0, KEYBOARD_DATA_MAX*sizeof(char));
    break;
  default:
    msg.CallType() = DEVICE_RETURN_ERROR;
    return;
  }

  msg.CallType() = DEVICE_RETURN_OK;
}
