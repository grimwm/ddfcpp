char *DDMMessage::GetAddress()
{
  return _message->m2_p1;
}

void DDMMessage::SetAddress(char *addr)
{
  _message->m2_p1 = addr;
}

long &DDMMessage::AddressSize()
{
  return _message->m2_l1;
}

id_t &DDMMessage::DriverPort()
{
  return _message->m2_i1;
}

long &DDMMessage::DriverCallType()
{
  return _message->m2_l2;
}
