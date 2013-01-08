#ifndef IDRIVER_PROXY_HPP__
#define IDRIVER_PROXY_HPP__

#include "IDriverInfo.hpp"

namespace SymbolX
{
  /// @brief Interface for communicating with a driver in general and a device
  ///	     in particular.
  class IDriver
  {
  public:
    /// @brief Constructor.
    inline IDriver() {}

    /// @brief Destructor.
    virtual ~IDriver() {}

    /// @brief Gives information about the current driver.
    /// @return A pointer to driver information.
    virtual IDriverInfo *GetDriverInfo() const = 0;

    /// @brief Opens a device.
    /// @param name Name of driver to open.
    /// @param deviceNumber Minor number of device to open.
    /// @return 0 on success and non-zero on error.
    virtual int Open(const DriverName &name, id_t deviceNumber) = 0;

    /// @brief Closes the current open device.
    /// @return 0 on success and non-zero on error.
    virtual int Close() = 0;

    /// @brief Reads inforamtion from the device.
    /// @param offset Where to start reading.
    /// @param count Length of data, in bytes, to read.
    /// @param output Where to store the read data.
    /// @return 0 on success and non-zero on error.
    virtual int Read(long offset, int count, unsigned char *output) = 0;

    /// Writes the @a count number of bytes from @a input to the device
    /// beginning at the device memory's @a offset.
    /// @param offset Where to start reading.
    /// @param count Length of data, in bytes, to read.
    /// @param input Data to be written.
    /// @return 0 on success and non-zero on error.
    virtual int Write(long offset, int count, unsigned char *input) = 0;

    /// @brief Executes a device-specific request.
    /// @param request Request for device to handle.
    /// @param data Associated data for request.
    /// @return 0 on success and non-zero on error.
    virtual int IOControl(int request, unsigned char *data) = 0;

    /// @brief Gathers data from the device.
    /// stores the results in @a output.
    /// @param offset Where to start reading.
    /// @param count Length of data, in bytes, to read.
    /// @param output Where to store the read data.
    /// @return 0 on success and non-zero on error.
    virtual int Gather(long offset, int count, unsigned char *output) = 0;

    /// @brief Scatters data across the device.
    /// @param offset Where to start reading.
    /// @param count Length of data, in bytes, to read.
    /// @param input Data to be written.
    /// @return 0 on success and non-zero on error.
    virtual int Scatter(long offset, int count, unsigned char *input) = 0;

    /// @brief Cancels the current operation.
    /// @return 0 on success and non-zero on error.
    virtual int Cancel() = 0;
  };
}

#endif
