// NOTE: This file is only to be included by IPC.hpp!

static inline int SendAndReceive(id_t to, IPCMessage &msg)
{
  return sendrec(to, msg.Serialize());
}

static inline int Send(id_t to, IPCMessage &msg)
{
  return send(to, msg.Serialize());
}

static inline int Receive(id_t from, IPCMessage &msg)
{
  return receive(from, msg.Serialize());
}
