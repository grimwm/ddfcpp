#ifndef MEMORY_HPP__
#define MEMORY_HPP__

#include "MemoryHeaders.hpp"
#include "IPCTypes.hpp"

namespace SymbolX
{
  /// @brief Provides methods related to accessing system memory.
  ///
  /// Methods that must be supported in any specialized support code:
  /// - static inline int Copy(id_t dst, long dstAddr, id_t src, long srcAddr,
  ///   size_t bytes): Copies virtual memory data from "src" to "dst".
  class Memory
  {
  public:
#ifdef Minix_OS__
#include "minix/Memory.hpp"
#endif
  };
}

#endif
