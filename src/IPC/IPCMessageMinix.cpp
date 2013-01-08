IPCMessageType *IPCMessage::Message()
{
  return _message;
}

id_t &IPCMessage::Sender()
{
  return _message->m_source;
}

id_t &IPCMessage::CallType()
{
  return _message->m_type;
}

id_t IPCMessage::SendAndReceive(id_t recipient)
{
  return sendrec(recipient, Message());
}

id_t IPCMessage::Send(id_t recipient)
{
  return send(recipient, Message());
}

id_t IPCMessage::Receive(id_t waitFor)
{
  return receive(waitFor, Message());
}
