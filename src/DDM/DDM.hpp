#ifndef DDM_HPP__
#define DDM_HPP__

#include "IPCTypes.hpp"

namespace SymbolX
{
  enum DDMMessageTypes {
    DDM_RETURN_OK,
    DDM_RETURN_ERROR,
    DDM_RETURN_FAILED_RESPONSE,
    
    DDM_NEXT,
    
    DDM_REGISTER,
    DDM_UNREGISTER,
    DDM_FIND_BUS_INFO,
    DDM_FIND_DRIVER_INFO,
    DDM_ENUMERATE_BUSSES,
    DDM_ENUMERATE_DRIVERS,
  };

#define DDM_MAX_DRIVER_NAME_LENGTH 1024
#define DDM_NULL_BUS_NAME "(null)"

#ifdef Minix_OS__
#include "DDMMinix.hpp"
#endif
}

#endif
