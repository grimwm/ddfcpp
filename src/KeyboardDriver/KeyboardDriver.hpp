#ifndef KEYBOARD_DRIVER_HPP__
#define KEYBOARD_DRIVER_HPP__

#include "Driver.hpp"

namespace SymbolX
{
#define KEYBOARD_DATA_MAX 1024

  enum KeyboardIOControlTypes {
    KEYBOARD_IOCTL_CLEAR_DATA,
  };

  class KeyboardDriver : public Driver
  {
  private:
    unsigned char _keyboardData[KEYBOARD_DATA_MAX];
    id_t _interruptId;
    unsigned _dataLocation;

  public:
    inline KeyboardDriver(char * const name="Keyboard") :
      Driver(name, DDM_NULL_BUS_NAME),
      _interruptId(0), _dataLocation(0) {}
    virtual ~KeyboardDriver() {}

    void Initialize();
    void InterruptHandler(DeviceInterruptMessage &msg);
    void ReadHandler(DeviceIOMessage &msg);
    void WriteHandler(DeviceIOMessage &msg);
    void IOControlHandler(DeviceIOControlMessage &msg);
  };
}

#endif
