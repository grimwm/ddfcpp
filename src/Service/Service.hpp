#ifndef SERVICE_HPP__
#define SERVICE_HPP__

#include "ServiceHeaders.hpp"

#define SERVICE_LOG(...) { \
  FILE *ofile = fopen("/var/log/debug.out", "a"); \
  if (ofile) { \
    fprintf(ofile, __VA_ARGS__); \
    fclose(ofile); \
  } \
}

namespace SymbolX
{
  /// @brief Provides methods related to diagnostic information.
  ///
  /// Methods that must be implemented on any OS implementing this class:
  /// - static void inline Panic(char * const id, char * const reason,
  ///        int errnum):
  ///    This causes the running application to panic and log an error
  ///    with the given "id", "reason", and "errnum".
  ///
  class Service
  {
  public:
#ifdef Minix_OS__
#include "minix/Service.hpp"
#endif
  };
}

#endif
