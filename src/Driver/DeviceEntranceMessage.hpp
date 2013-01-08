#ifndef DEVICE_ENTRANCE_MESSAGE_HPP__
#define DEVICE_ENTRANCE_MESSAGE_HPP__

#include "DeviceBaseMessage.hpp"

namespace SymbolX
{
  /// @brief Specializes messages related to opens and closes.
  class DeviceEntranceMessage : public DeviceBaseMessage
  {
  public:
    /// @brief Constructor.
    /// @param msg OS-specific IPC message to wrap.
    inline DeviceEntranceMessage(IPCMessageType *msg) :
      DeviceBaseMessage(msg) {}

    /// @brief Destructor.
    virtual ~DeviceEntranceMessage() {}
  };
}

#endif
