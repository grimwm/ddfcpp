#include "Driver.hpp"

using namespace SymbolX;

class ListenerDriver : public Driver
{
public:
  ListenerDriver() : Driver("ListenerDriver", DDM_NULL_BUS_NAME) {}
  virtual ~ListenerDriver() {}

  void Initialize() {}

  void OpenHandler(DeviceEntranceMessage &msg)
  {
    msg.CallType() = 0;
  }

  void ReadHandler(DeviceIOMessage &msg)
  {
    msg.CallType() = 1;
  }

  void WriteHandler(DeviceIOMessage &msg)
  {
    msg.CallType() = 2;
  }

  void CloseHandler(DeviceEntranceMessage &msg)
  {
    msg.CallType() = 3;
  }
};

int main()
{
  Driver *driver = new ListenerDriver();
  driver->Run();
  return 0;
}
