long &DeviceIOMessage::Offset()
{
  return _message->m2_l1;
}

int &DeviceIOMessage::Count()
{
  return _message->m2_i3;
}
