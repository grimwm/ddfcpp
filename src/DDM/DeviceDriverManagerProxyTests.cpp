#include <iostream>

#include "DeviceDriverManagerProxy.hpp"
#include "UnitTest.hpp"

using namespace SymbolX;
using namespace std;

static const char DRIVER_NAME[] = "DeviceDriverManagerProxyTests";

int main()
{
  IDeviceDriverManager *mgr = new DeviceDriverManagerProxy();
  IDriverInfo *info = new DriverInfo();

  int ret = mgr->RegisterDriver(DRIVER_NAME, DDM_NULL_BUS_NAME);
  cout << LongTest::compare(ret, DDM_RETURN_OK) << endl;

  ret = mgr->GetDriverInfo(info, DRIVER_NAME);
  cout << endl << LongTest::compare(ret, DDM_RETURN_OK) << endl;
  std::string result = info->Name();
  std::string expected = DRIVER_NAME;
  cout << endl << StringTest::compare(result, expected) << endl;
  result = info->BusOwner();
  expected = DDM_NULL_BUS_NAME;
  cout << endl << StringTest::compare(result, expected) << endl;

  StringList strings;
  ret = mgr->ListBusses(strings);
  cout << endl << LongTest::compare(ret, DDM_RETURN_OK) << endl;
  result = *strings.begin();
  expected = DDM_NULL_BUS_NAME;
  cout << endl << StringTest::compare(result, expected) << endl;
  strings.clear();

  ret = mgr->ListDrivers(strings);
  cout << endl << LongTest::compare(ret, DDM_RETURN_OK) << endl;
  result = *strings.begin();
  expected = DRIVER_NAME;
  cout << endl << StringTest::compare(result, expected) << endl;
  strings.clear();

  ret = mgr->ListDriversOnBus(strings, DDM_NULL_BUS_NAME);
  cout << endl << LongTest::compare(ret, DDM_RETURN_OK) << endl;
  result = *strings.begin();
  expected = DRIVER_NAME;
  cout << endl << StringTest::compare(result, expected) << endl;
  strings.clear();

  ret = mgr->UnregisterDriver(DRIVER_NAME);
  cout << endl << LongTest::compare(ret, DDM_RETURN_OK) << endl;

  ret = mgr->GetDriverInfo(info, DRIVER_NAME);
  cout << endl << LongTest::compare(ret, DDM_RETURN_ERROR) << endl;

  ret = mgr->ListBusses(strings);
  cout << endl << LongTest::compare(ret, DDM_RETURN_OK) << endl;

  ret = mgr->ListDrivers(strings);
  cout << endl << LongTest::compare(ret, DDM_RETURN_OK) << endl;

  ret = mgr->ListDriversOnBus(strings, DDM_NULL_BUS_NAME);
  cout << endl << LongTest::compare(ret, DDM_RETURN_ERROR) << endl;

  delete mgr;

  return 0;
}
