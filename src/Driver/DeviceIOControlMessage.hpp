#ifndef DEVICE_IO_CONTROL_MESSAGE_HPP__
#define DEVICE_IO_CONTROL_MESSAGE_HPP__

#include "DeviceBaseMessage.hpp"

namespace SymbolX
{
  /// @brief Specializes messages related to I/O controls.
  class DeviceIOControlMessage : public DeviceBaseMessage
  {
  public:
    /// @brief Constructor.
    /// @param msg OS-specific IPC message to wrap.
    inline DeviceIOControlMessage(IPCMessageType *msg) :
      DeviceBaseMessage(msg) {}

    /// @brief Destructor.
    virtual ~DeviceIOControlMessage() {}

    /// @brief Sets and gets the I/O control request.
    /// @return Reference to the I/O control request.
    virtual int &Request();
  };
}

#endif
