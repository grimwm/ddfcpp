#ifndef IPC_HPP__
#define IPC_HPP__

#include "IPCTypes.hpp"
#include "IPCMessage.hpp"

namespace SymbolX
{
  /// @brief Provides methods related to IPC messages.
  ///
  /// Methods that must be supported in any specialized support code:
  /// - static inline int SendAndReceive(id_t to, IPCMessage &msg): Sends
  ///	a message to another process and blocks until a response is received.
  /// - static inline Send(id_t to, IPCMessage &msg): Sends a message to
  ///	another process.
  /// - static inline Receive(id_t from, IPCMessage &msg): Receives a mesage
  ///	from another process indicated by "from".
  class IPC
  {
  public:
#ifdef Minix_OS__
#include "IPCMinix.hpp" 
#endif
  };
}

#endif
