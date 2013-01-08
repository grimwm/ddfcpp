#ifndef IDEVICE_DRIVER_MANAGER_HPP__
#define IDEVICE_DRIVER_MANAGER_HPP__

#include "Types.hpp"
#include "DriverInfo.hpp"

namespace SymbolX
{
  /// @brief Interface for communicating with the device driver manager.
  class IDeviceDriverManager
  {
  public:
    /// @brief Constructor.
    inline IDeviceDriverManager() {}

    /// @brief Destructor.
    virtual ~IDeviceDriverManager() {}

    /// @brief Registers a driver with the DDM.
    /// @param name Name of the driver.
    /// @param busOwner Bus where the driver resides.
    /// @return 0 for success or non-zero for failure.
    virtual int RegisterDriver(const char *name, const char *busOwner) = 0;

    /// @brief Unregisters a driver previously registered with the DDM.
    /// @param name Name of the driver.
    /// @return 0 for success or non-zero for failure.
    virtual int UnregisterDriver(const char *name) = 0;

    /// @brief Returns driver information of a named driver known by the DDM.
    /// @param info Location where driver information is to be saved.
    /// @param name Name of the driver.
    /// @return 0 for success or non-zero for failure.
    virtual int GetDriverInfo(IDriverInfo *info, const char *name) = 0;

    /// @brief Lists all the busses registered with the DDM.
    /// @param busses Location where a comma-separated list of busses will
    ///		      be stored.
    /// @return 0 for success or non-zero for failure.
    virtual int ListBusses(StringList &busses) = 0;

    /// @brief Lists all the drivers registered with the DDM.
    /// @param drivers Location where a comma-separated list of drivers
    ///		       will be stored.
    /// @return 0 for success or non-zero for failure.
    virtual int ListDrivers(StringList &drivers) = 0;

    /// @brief Lists all the drivers registered with a bus known by the DDM.
    /// @param drivers Location where a comma-separated list of drivers
    ///		       will be stored.
    /// @param busName Name of the bus.
    /// @return 0 for success or non-zero for failure.
    virtual int ListDriversOnBus(StringList &drivers,
				 const char *busName) = 0;
  };
}

#endif
