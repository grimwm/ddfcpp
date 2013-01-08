long &DeviceIOVectorMessage::Offset()
{
  return _message->POSITION;
}

int &DeviceIOVectorMessage::Count()
{
  return _message->COUNT;
}
