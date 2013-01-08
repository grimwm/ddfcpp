#include "DriverInfo.hpp"

using namespace SymbolX;

id_t DriverInfo::CommunicationPort() const
{
  return _port;
}

DriverName DriverInfo::Name() const
{
  return _name;
}

DriverName DriverInfo::BusOwner() const
{
  return _busOwner;
}
