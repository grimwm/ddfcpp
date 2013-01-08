#ifndef DRIVER_INFO_HPP__
#define DRIVER_INFO_HPP__

#include "IDriverInfo.hpp"
#include "DDMMessage.hpp"

namespace SymbolX
{
  /// @brief Implementation of the IDriverInfo interface.
  class DriverInfo : public IDriverInfo
  {
  private:
    /// @brief Listening port for this driver.
    id_t _port;

    /// @brief Name of this driver.
    DriverName _name;

    /// @brief Bus where this driver is attached.
    DriverName _busOwner;
    
  public:
    /// @brief Constructor.
    inline DriverInfo()
    {
    }
    
    /// @brief Copy constructor.
    /// @param info Driver information to copy.
    inline DriverInfo(IDriverInfo &info) :
      _port(info.CommunicationPort()), _name(info.Name()),
      _busOwner(info.BusOwner())
    {
    }
    
    /// @brief Constructor.
    /// @param port Port where driver is listening.
    /// @param name Name of driver.
    /// @param owner Bus where driver is attached.
    inline DriverInfo(id_t port, DriverName name, DriverName owner) :
      _port(port), _name(name), _busOwner(owner)
    {
    }

    /// @brief Destructor.    
    virtual  ~DriverInfo()
    {
    }
    
    /// @brief Returns the port where the driver is listening.
    /// @return Driver's listening port.
    id_t CommunicationPort() const;

    /// @brief Returns the name of the driver.
    /// @return Driver's name.
    DriverName Name() const;

    /// @brief Returns the bus where the driver is attached.
    /// @return Driver's bus owner.
    DriverName BusOwner() const;
    
    /// @brief Copies an IDriverInfo object from a remote location.
    /// @param dst Location where driver information will be stored.
    /// @param port Communication port of remote server that contains
    ///		    driver information.
    /// @param name The name of the driver of interest.
    /// @return True if copy successful; otherwise, returns false.
    static inline bool RemoteCopy(IDriverInfo &dst, id_t port,
				  const DriverName &name)
    {
      DriverInfo &info = static_cast<DriverInfo&>(dst);
      IPCMessageType msg;
      DDMMessage ddm(&msg);
      ddm.CallType() = DDM_FIND_DRIVER_INFO;
      ddm.AddressSize() = name.size();
      ddm.SetAddress((char*)name.c_str());
      int ret = ddm.SendAndReceive(port);
      if (ret || DDM_NEXT != ddm.CallType()) {
	return false;
      }
      
      info._port = ddm.DriverPort();
      info._name = name;
      
      char cname[ddm.AddressSize()];
      memset(cname, 0, ddm.AddressSize());
      ddm.SetAddress(cname);
      
      ret = ddm.SendAndReceive(port);
      if (ret || DDM_RETURN_OK != ddm.CallType()) {
	return false;
      }
      cname[ddm.AddressSize()-1] = '\0';
      info._busOwner = cname;
      
      return true;
    }
  };
}

#endif
