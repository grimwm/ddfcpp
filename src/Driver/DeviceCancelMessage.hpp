#ifndef DEVICE_CANCEL_MESSAGE_HPP__
#define DEVICE_CANCEL_MESSAGE_HPP__

#include "DeviceBaseMessage.hpp"

namespace SymbolX
{
  /// @brief Specializes messages related to cancels.
  class DeviceCancelMessage : public DeviceBaseMessage
  {
  public:
    /// @brief Constructor.
    /// @param msg OS-specific IPC message to wrap.
    inline DeviceCancelMessage(IPCMessageType *msg) :
      DeviceBaseMessage(msg) {}

    /// @brief Destructor.
    virtual ~DeviceCancelMessage() {}
  };
}

#endif
