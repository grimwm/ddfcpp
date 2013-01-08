#include <fstream>

#include "KeyboardDriver.hpp"
#include "UnitTest.hpp"
#include "Service.hpp"

using namespace SymbolX;
using namespace std;

#define HANDLER_LOG { \
  std::string str = __func__; \
  str += " called:  DevNum:%d  DevAddr:0x%X  DevAddrLen:%lu\n"; \
  SERVICE_LOG(str.c_str(), \
      msg.DeviceNumber(), msg.GetAddress(), msg.AddressSize()); \
}

class MockKeyboardDriver : public KeyboardDriver
{
public:
  bool initializeCalled;
  bool interruptCalled;
  bool readCalled;
  bool writeCalled;
  bool ioctlCalled;
  bool scatterCalled;
  bool gatherCalled;
  bool openCalled;
  bool closeCalled;
  bool cancelCalled;
  bool quitCalled;

  MockKeyboardDriver() :
    KeyboardDriver("MockKeyboardDriver"), initializeCalled(false),
    interruptCalled(false), readCalled(false), writeCalled(false),
    ioctlCalled(false), scatterCalled(false), gatherCalled(false),
    openCalled(false), closeCalled(false), cancelCalled(false),
    quitCalled(false)
  {}
  virtual ~MockKeyboardDriver() {}

  void Initialize()
  {
    std::string str = __func__;
    str += " called.\n";
    SERVICE_LOG(str.c_str());
    initializeCalled = true;
    KeyboardDriver::Initialize();
  }

  void InterruptHandler(DeviceInterruptMessage &msg)
  {
    HANDLER_LOG;
    interruptCalled = true;
    KeyboardDriver::InterruptHandler(msg);
  }

  void ReadHandler(DeviceIOMessage &msg)
  {
    HANDLER_LOG;
    SERVICE_LOG("\t\t\tOffset:%lu  Count:%u\n", msg.Offset(), msg.Count());
    readCalled = true;
    KeyboardDriver::ReadHandler(msg);
  }

  void WriteHandler(DeviceIOMessage &msg)
  {
    HANDLER_LOG;
    SERVICE_LOG("\t\t\tOffset:%lu  Count:%u\n", msg.Offset(), msg.Count());
    writeCalled = true;
    KeyboardDriver::WriteHandler(msg);
  }

  void IOControlHandler(DeviceIOControlMessage &msg)
  {
    HANDLER_LOG;
    ioctlCalled = true;
    KeyboardDriver::IOControlHandler(msg);
  }

  void ScatterHandler(DeviceIOVectorMessage &msg)
  {
    HANDLER_LOG;
    scatterCalled = true;
    KeyboardDriver::ScatterHandler(msg);
  }

  void GatherHandler(DeviceIOVectorMessage &msg)
  {
    HANDLER_LOG;
    gatherCalled = true;
    KeyboardDriver::GatherHandler(msg);
  }

  void OpenHandler(DeviceEntranceMessage &msg)
  {
    HANDLER_LOG;
    openCalled = true;
    KeyboardDriver::OpenHandler(msg);
  }

  void CloseHandler(DeviceEntranceMessage &msg)
  {
    HANDLER_LOG;
    closeCalled = true;
    KeyboardDriver::CloseHandler(msg);
  }

  void CancelHandler(DeviceCancelMessage &msg)
  {
    HANDLER_LOG;
    cancelCalled = true;
    KeyboardDriver::CancelHandler(msg);
  }

  void QuitHandler()
  {
    std::string str = __func__;
    str += " called.\n";
    SERVICE_LOG(str.c_str());
    quitCalled = true;

    ofstream fout("/tmp/MockKeyboardDriver.out");
    if (!fout) {
      return;
    }

    fout << endl << BoolTest::compare(initializeCalled, true) << endl;
    fout << endl << BoolTest::compare(interruptCalled, true) << endl;
    fout << endl << BoolTest::compare(readCalled, true) << endl;
    fout << endl << BoolTest::compare(writeCalled, true) << endl;
    fout << endl << BoolTest::compare(ioctlCalled, true) << endl;
    fout << endl << BoolTest::compare(scatterCalled, true) << endl;
    fout << endl << BoolTest::compare(gatherCalled, true) << endl;
    fout << endl << BoolTest::compare(openCalled, true) << endl;
    fout << endl << BoolTest::compare(closeCalled, true) << endl;
    fout << endl << BoolTest::compare(cancelCalled, true) << endl;
    fout << endl << BoolTest::compare(quitCalled, true) << endl;

    fout.close();

    KeyboardDriver::QuitHandler();
  }

  IDeviceDriverManager *DDM()
  {
    return _ddm;
  }
};

int main(int argc, const char *argv[])
{
  MockKeyboardDriver *driver = new MockKeyboardDriver();
  driver->Run();
  delete driver;

  return 0;
}
