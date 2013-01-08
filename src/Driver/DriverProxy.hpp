#ifndef DRIVER_PROXY_HPP__
#define DRIVER_PROXY_HPP__

#include "IDriver.hpp"
#include "DeviceMessages.hpp"

#include "DeviceDriverManagerProxy.hpp"

namespace SymbolX
{
  /// @brief Implementation of the IDriver interface.
  ///
  /// Provides methods that make communication with a driver seem like
  /// local method calls.  It does this by being a proxy between the client
  /// and the driver and handling all the communication protocols underneat
  /// the hood.
  class DriverProxy : public IDriver
  {
  private:
    /// @brief DDM associated with the driver.
    IDeviceDriverManager * const _ddm;

    /// @brief OS-specific IPC message.
    IPCMessageType *_message;

    /// @brief Information about this driver.
    IDriverInfo *_info;

    /// @brief Keeps track of whether this driver instance has already been
    ///	       opened or not.
    bool _alreadyOpen;

    /// @brief Device number associated with this driver.
    id_t _deviceNumber;

  public:
    /// @brief Constructor.
    inline DriverProxy() :
      _ddm(new DeviceDriverManagerProxy()), _message(new IPCMessageType()),
      _info(new DriverInfo()), _alreadyOpen(false), _deviceNumber(0)
    {
    }

    /// @brief Destructor.
    virtual ~DriverProxy()
    {
      delete _ddm;
      delete _message;
      if (_info) {
	delete _info;
      }
    }

    /// @brief Returns information about this driver.
    /// @return Pointer to information about this driver.
    IDriverInfo *GetDriverInfo() const;

    /// @brief Opens a device using a driver with a given name and minor
    ///	       number.
    /// @param name Name of driver to open.
    /// @param deviceNumber Minor device number to open using driver.
    /// @return 0 on success and non-zero otherwise.
    int Open(const DriverName &name, id_t deviceNumber);

    /// @brief Closes this driver.
    /// @return 0 on success and non-zero otherwise.
    int Close();

    /// @brief Reads data from the device.
    /// @param offset Where to start reading data on the device.
    /// @param count Number of bytes to read from the device.
    /// @param output Where to store the data read from the device.
    /// @return 0 on success and non-zero otherwise.
    int Read(long offset, int count, unsigned char *output);

    /// @brief Writes data to the device.
    /// @param offset Where to start writing data on the device.
    /// @param count Number of bytes to write to the device.
    /// @param input Where to read the data to be stored on the device.
    /// @return 0 on success and non-zero otherwise.
    int Write(long offset, int count, unsigned char *input);

    /// @brief Execute a special command on the device.
    /// @param request Command to execute.
    /// @param data Data associated with the command.
    /// @return 0 on success and non-zero otherwise.
    int IOControl(int request, unsigned char *data);

    /// @brief Gathers data from the device.
    /// @param offset Where to start gather data on the device.
    /// @param count Number of bytes to gather from the device.
    /// @param output Where to store the gathered information.
    /// @return 0 on success and non-zero otherwise.
    int Gather(long offset, int count, unsigned char *output);

    /// @brief Scatters information across the device.
    /// @param offset Where to start scattering data on the device.
    /// @param count Number of bytes to scatter on the device.
    /// @param input Where the information to be scattered is currently stored.
    /// @return 0 on success and non-zero otherwise.
    int Scatter(long offset, int count, unsigned char *input);

    /// @brief Cancels an operation.
    /// @return 0 on success and non-zero otherwise.
    int Cancel();
  };
}

#endif
