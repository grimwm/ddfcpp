#ifndef IDRIVER_INFO_HPP__
#define IDRIVER_INFO_HPP__

#include "IPCTypes.hpp"
#include "DriverInfoTypes.hpp"

namespace SymbolX
{
  /// @brief Interface for getting information related to a specific driver.
  class IDriverInfo
  {
  public:
    /// @brief Constructor.
    inline IDriverInfo() {}

    /// @brief Destructor.
    virtual ~IDriverInfo() {}

    /// @brief Returns the communication port to which the driver is listening.
    /// @return Driver's listening port.
    virtual id_t CommunicationPort() const = 0;

    /// @brief Gives the name of the driver.
    /// @return The name of the driver.
    virtual DriverName Name() const = 0;

    /// @brief Gives the bus to which the driver is connected.
    /// @return The bus where the driver resides.
    virtual DriverName BusOwner() const = 0;
  };
}

#endif
