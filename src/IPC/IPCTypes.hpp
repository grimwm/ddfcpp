#ifndef IPC_TYPES__
#define IPC_TYPES__

#ifdef Minix_OS__
#include <ansi.h>
#include <minix/type.h>
#include <minix/com.h>
#include <minix/ipc.h>
#include <minix/sysutil.h>
#endif

namespace SymbolX
{
#ifdef Minix_OS__
  typedef int id_t;
  typedef message IPCMessageType;

#define ANY_PROC  ANY
#define SELF_PROC SELF
#define NO_PROC   NONE
#endif
}

#endif
