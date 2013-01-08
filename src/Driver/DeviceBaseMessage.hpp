#ifndef DEVICE_BASE_MESSAGE_HPP__
#define DEVICE_BASE_MESSAGE_HPP__

#include "IPCMessage.hpp"

namespace SymbolX
{
  /// @brief Specializes messages to a base type that can be derived by
  ///	     other classes that contain information for driver requests.
  class DeviceBaseMessage : public IPCMessage
  {
  public:
    /// @brief Constructor.
    /// @param msg OS-specific IPC message to wrap.
    inline DeviceBaseMessage(IPCMessageType *msg) : IPCMessage(msg) {}

    /// @brief Destructor.
    virtual ~DeviceBaseMessage() {}

    /// @brief Sets and gets the device number.
    /// @return Reference to the device's minor number.
    virtual id_t &DeviceNumber();

    /// @brief Gets the address to a memory location with data.
    /// @return Pointer to the data's memory location.
    virtual char *GetAddress();

    /// @brief Sets the address to a memory location with data.
    /// @param addr Memory location with data.
    virtual void SetAddress(char *addr);

    /// @brief Sets and gets the size of the memory given in SetAddress.
    /// @return Reference to the size of the memory given in SetAddress.
    virtual long &AddressSize();
  };
}

#endif
