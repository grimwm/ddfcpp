#ifndef IPC_MESSAGE_HPP__
#define IPC_MESSAGE_HPP__

#include "IIPCMessage.hpp"

namespace SymbolX
{
  /// @brief Implementation of the IIPCMessage interface.
  class IPCMessage : public IIPCMessage
  {
  protected:
    /// @brief OS-specific IPC message pointer.
    IPCMessageType *_message;

  public:
    /// @brief Constructor.
    /// @param msg OS-specific message to support.
    inline IPCMessage(IPCMessageType *msg) : _message(msg) {}

    virtual ~IPCMessage() {}

    IPCMessageType *Message();
    id_t &Sender();
    id_t &CallType();
    id_t SendAndReceive(id_t recipient);
    id_t Send(id_t recipient);
    id_t Receive(id_t waitFor);
  };
}

#endif
