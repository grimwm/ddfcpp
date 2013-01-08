#ifndef DEVICE_IO_MESSAGE_HPP__
#define DEVICE_IO_MESSAGE_HPP__

#include "DeviceBaseMessage.hpp"

namespace SymbolX
{
  /// @brief Specializes messages related to reads and writes.
  class DeviceIOMessage : public DeviceBaseMessage
  {
  public:
    /// @brief Constructor.
    /// @param msg OS-specific IPC message to wrap.
    inline DeviceIOMessage(IPCMessageType *msg) :
      DeviceBaseMessage(msg) {}

    /// @brief Destructor.
    virtual ~DeviceIOMessage() {}

    /// @brief Sets and gets the offset of the beginning of data to read or
    ///	       write to the device.
    /// @return Reference to the offset.
    long &Offset();

    /// @brief Sets and gets the number of bytes to read or write to the
    ///	       device.
    /// @return Reference to the number of bytes.
    int &Count();
  };
}

#endif
