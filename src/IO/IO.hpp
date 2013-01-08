#ifndef IO_HPP__
#define IO_HPP__

#include "IOHeaders.hpp"

namespace SymbolX
{
  /// @brief Contains methods related to I/O.
  ///
  /// Methods that must be supported by any OS implementing IO.hpp:
  /// - static inline int InstallInterruptHandler(id_t irq, id_t *id):
  ///    Install an interrupt handler for the "irq" vector.  "id" will be
  ///    the value returned when an interrupt is raised.
  /// - static inline int EnableInterruptHandler(id_t irq, id_t *id):
  ///    Enable interrupt handler identified by "id".
  ///
  /// - static inline unsigned long ReadByte(int port):
  ///    Read a byte from the IO device specified with "port".
  /// - static inline unsigned long ReadWord(int port):
  ///    Read a word from the IO device specified with "port".
  /// - static inline unsigned long ReadDWord(int port):
  ///    Read a double-word from the IO device specified with "port".
  ///
  /// - static inline void WriteByte(int port, unsigned long byte):
  ///    Write "byte" to the IO device specified with "port".
  /// - static inline void WriteWord(int port, unsigned long word):
  ///    Write "word" to the IO device specified with "port".
  /// - static inline void WriteDWord(int port, unsigned long dword):
  ///    Write "dword" to the IO device specified with "port".
  class IO
  {
  public:
#ifdef Minix_OS__
#include "minix/IO.hpp"
#endif

  };
}

#endif
