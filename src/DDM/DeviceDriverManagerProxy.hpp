#ifndef DEVICE_DRIVER_MANAGER_PROXY_HPP__
#define DEVICE_DRIVER_MANAGER_PROXY_HPP__

#include "IDeviceDriverManager.hpp"
#include "DDMMessage.hpp"

namespace SymbolX
{
  /// @brief Implementation of the IDeviceDriverManager interface.
  ///
  /// The purpose of this class is to make communication with the DDM seem
  /// like a set of local method calls.  In reality, it's a proxy that handles
  /// a more complex communication protocol underneath.
  class DeviceDriverManagerProxy : public IDeviceDriverManager
  {
  private:
    /// @brief OS-specific IPC message.
    IPCMessageType *_ipcMessage;

    /// @brief Message handler for DDM communication.  Uses _ipcMessage for
    /// underlying communication.
    DDMMessage _message;

    int _parseCSVIntoStringList(StringList &resultList);

  public:
    /// @brief Constructor.
    inline DeviceDriverManagerProxy() :
      _ipcMessage(new IPCMessageType),
      _message(_ipcMessage) {}

    /// @brief Destructor.
    virtual ~DeviceDriverManagerProxy()
    {
      delete _ipcMessage;
    }

    /// @brief Registers a driver with the DDM.
    /// @param name Name of the driver.
    /// @param busOwner Bus where driver is attached.
    /// @return 0 on success or non-zero otherwise.
    int RegisterDriver(const char *name, const char *busOwner);

    /// @brief Unregisters a driver previously registered with the DDM.
    /// @param name Name of the driver to unregister.
    /// @return 0 on success or non-zero otherwise.
    int UnregisterDriver(const char *name);

    /// @brief Gets information about a driver in question.
    /// @param info Location where driver information will be stored.
    /// @param name Name of driver of interest.
    /// @return 0 on success or non-zero otherwise.
    int GetDriverInfo(IDriverInfo *info, const char *name);

    /// @brief Returns a comma-separated listing of busses known by the DDM.
    /// @param busses Location where bus listing will be stored.
    /// @return 0 on success or non-zero otherwise.
    int ListBusses(StringList &busses);

    /// @brief Returns a comma-separated listing of drivers known by the DDM.
    /// @param drivers Location where driver listing will be stored.
    /// @return 0 on success or non-zero otherwise.
    int ListDrivers(StringList &drivers);

    /// @brief Returns a comma-separated listing of drivers known by the DDM
    ///	       on a particular bus.
    /// @param drivers Location where driver listing will be stored.
    /// @param busName Name of bus holding drivers.
    /// @return 0 on success or non-zero otherwise.
    int ListDriversOnBus(StringList &drivers, const char *busName);
  };
}

#endif
