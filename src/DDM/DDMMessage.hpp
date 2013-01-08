#ifndef DDM_MESSAGE_HPP__
#define DDM_MESSAGE_HPP__

#include "IPCMessage.hpp"
#include "DDM.hpp"

namespace SymbolX
{
  /// @brief Derivative of the IPCMessage class.
  ///
  /// Provides a customization of the IPCMessage class that makes passing
  /// specific kinds of data with the DDM easier.
  class DDMMessage : public IPCMessage
  {
  public:
    /// @brief Constructor.
    /// @param msg OS-specific IPC message to wrap.
    inline DDMMessage(IPCMessageType *msg) : IPCMessage(msg) {}

    /// @brief Destructor.
    virtual ~DDMMessage() {}

    /// @brief Gets the address of a memory location.
    /// @return Address of a location in memory.
    char *GetAddress();

    /// @brief Stores the address of a memory location.
    /// @param addr Address of memory to reference.
    void SetAddress(char *addr);

    /// @brief Sets and gets the length of the data at the stored memory
    ///	       location.
    /// @return Reference to the data's length in memory.
    long &AddressSize();

    /// @brief Sets and gets the driver's listening port.
    /// @return Reference to the driver's listening port.
    id_t &DriverPort();

    /// @brief Sets and gets the driver's method.
    /// @return Reference to the driver's method.
    long &DriverCallType();
  };
}

#endif
