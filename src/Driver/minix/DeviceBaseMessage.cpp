id_t &DeviceBaseMessage::DeviceNumber()
{
  return _message->DEVICE;
}

char *DeviceBaseMessage::GetAddress()
{
  return _message->ADDRESS;
}

void DeviceBaseMessage::SetAddress(char *addr)
{
  _message->ADDRESS = addr;
}

long &DeviceBaseMessage::AddressSize()
{
  return _message->m2_l2;
}
