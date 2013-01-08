#ifndef IIPCMESSAGE_HPP__
#define IIPCMessage_HPP__

#include "IPCTypes.hpp"

namespace SymbolX
{
  /// @brief Interface for constructing and using IPC messages.
  class IIPCMessage
  {
  public:
    /// @brief Constructor.
    inline IIPCMessage() {}

    /// @brief Destructor.
    virtual ~IIPCMessage() {}

    /// @brief Provides access to the native OS' raw message type and data.
    /// @return The native OS' raw message type and data.
    virtual IPCMessageType *Message() = 0;

    /// @brief Identifies the sender of the message.
    /// @return The id of the sender.
    virtual id_t &Sender() = 0;

    /// @brief Tells the type of message sent.
    /// @return The type of call.
    virtual id_t &CallType() = 0;

    /// @brief Sends a message and waits for a response.
    /// @param recipient Where message will be sent.
    /// @return 0 on success or non-zero otherwise.
    virtual id_t SendAndReceive(id_t recipient) = 0;

    /// @brief Sends a message to another.
    /// @param recipient Where message will be sent.
    /// @return 0 on success or non-zero otherwise.
    virtual id_t Send(id_t recipient) = 0;

    /// @brief Waits for a message to be received by a particular entity.
    /// @param waitFor The one sending the message.
    /// @return 0 on success or non-zero otherwise.
    virtual id_t Receive(id_t waitFor) = 0;
  };
}

#endif
