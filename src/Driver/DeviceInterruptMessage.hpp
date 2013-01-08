#ifndef DEVICE_INTERRUPT_MESSAGE_HPP__
#define DEVICE_INTERRUPT_MESSAGE_HPP__

#include "DeviceBaseMessage.hpp"

namespace SymbolX
{
  /// @brief Specializes messages related to interrupts.
  class DeviceInterruptMessage : public DeviceBaseMessage
  {
  public:
    /// @brief Constructor.
    /// @param msg OS-specific IPC message to wrap.
    inline DeviceInterruptMessage(IPCMessageType *msg) :
      DeviceBaseMessage(msg) {}

    /// @brief Destructor.
    virtual ~DeviceInterruptMessage() {}
  };
}

#endif
