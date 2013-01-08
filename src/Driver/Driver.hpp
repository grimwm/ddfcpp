#ifndef DRIVER_HPP__
#define DRIVER_HPP__

#include "DeviceMessages.hpp"
#include "DeviceDriverManagerProxy.hpp"

namespace SymbolX
{
  /// @brief Implements a skeleton driver that returns
  ///	     DEVICE_RETURN_ERROR_NOT_IMPLEMENTED messages.
  class Driver
  {
  protected:
    /// @brief Name of the driver.
    char * const _name;

    /// @brief Bus where driver is attached.
    char * const _busOwner;

    /// @brief DDM where driver is registered.
    IDeviceDriverManager *_ddm;

  public:
    /// @brief Constructor.
    /// @param name Name of driver.
    /// @param busOwner Bus where driver is attached.
    inline Driver(char * const name, char * const busOwner) :
      _name(name),
      _busOwner(busOwner),
      _ddm(new DeviceDriverManagerProxy()) {}

    /// @brief Destructor.
    virtual ~Driver() {}

    /// @brief Begins execution of driver.
    virtual void Run();

    /// @brief Initializes any special data associated with driver.
    virtual void Initialize() = 0;

    /// @brief Handles interrupts.
    /// @param msg Information related to the interrupt.
    virtual void InterruptHandler(DeviceInterruptMessage &msg);

    /// @brief Handles read requests.
    /// @param msg Information related to the read operation.
    virtual void ReadHandler(DeviceIOMessage &msg);

    /// @brief Handles write requests.
    /// @param msg Information related to the write operation.
    virtual void WriteHandler(DeviceIOMessage &msg);

    /// @brief Handles I/O control requests.
    /// @param msg Information related to the I/O control operation.
    virtual void IOControlHandler(DeviceIOControlMessage &msg);

    /// @brief Handles scatter request.
    /// @param msg Information related to the scatter request.
    virtual void ScatterHandler(DeviceIOVectorMessage &msg);

    /// @brief Handles gather request.
    /// @param msg Information related to the gather request.
    virtual void GatherHandler(DeviceIOVectorMessage &msg);

    /// @brief Handles open request.
    /// @param msg Information related to the open request.
    virtual void OpenHandler(DeviceEntranceMessage &msg);

    /// @brief Handles close request.
    /// @param msg Information related to the close request.
    virtual void CloseHandler(DeviceEntranceMessage &msg);

    /// @brief Handles cancel request.
    /// @param msg Information related to the cancel request.
    virtual void CancelHandler(DeviceCancelMessage &msg);

    /// @brief Handles timeout request.
    /// @param msg Information related to the timeout request.
    virtual void TimeoutHandler(DeviceTimeoutMessage &msg);

    /// @brief Handles quit request.
    virtual void QuitHandler();
  };
}

#endif
