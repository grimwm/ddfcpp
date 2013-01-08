#ifndef DEVICE_MESSAGE_TYPES_HPP__
#define DEVICE_MESSAGE_TYPES_HPP__

#ifdef Minix_OS__
#include "minix/DeviceMessageTypesHeaders.hpp"
#endif

namespace SymbolX
{
  /// @brief Provides a set of supported messages that device drivers
  ///	     understand.
  ///
  /// Macros or enumerated tpes that must be defined in all platform-specific
  /// code:
  ///    - DEVICE_INTERRUPT
  ///    - DEVICE_READ
  ///    - DEVICE_WRITE
  ///    - DEVICE_IO_CONTROL
  ///    - DEVICE_OPEN
  ///    - DEVICE_CLOSE
  ///    - DEVICE_SCATTER
  ///    - DEVICE_GATHER
  ///    - DEVICE_CANCEL

#ifdef Minix_OS__
#include "minix/DeviceMessageTypes.hpp"
#endif

  enum DeviceMessageTypes {
    DEVICE_RETURN_OK,
    DEVICE_RETURN_ERROR,
    DEVICE_RETURN_ERROR_NOT_IMPLEMENTED,

    DEVICE_RETURN_PROXY_ALREADY_OPEN,
  };
}

#endif
