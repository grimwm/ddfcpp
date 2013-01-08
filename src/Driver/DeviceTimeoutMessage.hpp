#ifndef DEVICE_TIMEOUT_MESSAGE_HPP__
#define DEVICE_TIMEOUT_MESSAGE_HPP__

#include "DeviceBaseMessage.hpp"

namespace SymbolX
{
  /// @brief Specializes messages related to timeouts.
  class DeviceTimeoutMessage : public DeviceBaseMessage
  {
  public:
    /// @brief Constructor.
    /// @param msg OS-specific IPC message to wrap.
    inline DeviceTimeoutMessage(IPCMessageType *msg) :
      DeviceBaseMessage(msg) {}

    /// @brief Destructor.
    virtual ~DeviceTimeoutMessage() {}
  };
}

#endif
