#include <iostream>
#include <cstdio>

#include "DDMMessage.hpp"
#include "DriverInfo.hpp"
#include "DDM.hpp"

#include "UnitTest.hpp"

using namespace std;
using namespace SymbolX;

static const char DRIVER_NAME[] = "DeviceDriverManagerTests";
static const char BUS_NAME[] = "DeviceDriverManager";
static char *_driverList = NULL;

int main()
{
  IPCMessageType ipcMsg;
  DDMMessage msg(&ipcMsg);
  id_t proc = ddmFindProcessID();

  //------------- REGISTER DRIVER
  msg.CallType() = DDM_REGISTER;
  msg.AddressSize() = strlen(DRIVER_NAME);
  msg.SetAddress((char*)DRIVER_NAME);
  int ret = msg.SendAndReceive(proc);
  cout << LongTest::compare(ret, 0) << endl;
  cout << endl << LongTest::compare(msg.CallType(), DDM_NEXT) << endl;

  msg.AddressSize() = strlen(DDM_NULL_BUS_NAME);
  msg.SetAddress(DDM_NULL_BUS_NAME);
  ret = msg.SendAndReceive(proc);
  cout << endl << LongTest::compare(ret, 0) << endl;
  cout << endl << LongTest::compare(msg.CallType(), DDM_RETURN_OK) << endl;

  //------------- ENUMERATE DRIVERS
  msg.CallType() = DDM_ENUMERATE_DRIVERS;
  ret = msg.SendAndReceive(proc);
  cout << endl << LongTest::compare(ret, 0) << endl;
  cout << endl << LongTest::compare(msg.CallType(), DDM_NEXT) << endl;

  _driverList = new char[msg.AddressSize()];
  memset(_driverList, 0, msg.AddressSize()*sizeof(char));
  msg.SetAddress(_driverList);
  ret = msg.SendAndReceive(proc);
  cout << endl << LongTest::compare(ret, 0) << endl;
  cout << endl << LongTest::compare(msg.CallType(), DDM_RETURN_OK) << endl;
  DriverName result = _driverList;
  DriverName expected = "DeviceDriverManagerTests";
  cout << endl << StringTest::compare(result, expected) << endl;
  delete _driverList;

  //------------- ENUMERATE BUSSES
  msg.CallType() = DDM_ENUMERATE_BUSSES;
  ret = msg.SendAndReceive(proc);
  cout << endl << LongTest::compare(ret, 0) << endl;
  cout << endl << LongTest::compare(msg.CallType(), DDM_NEXT) << endl;

  _driverList = new char[msg.AddressSize()];
  memset(_driverList, 0, msg.AddressSize()*sizeof(char));
  msg.SetAddress(_driverList);
  ret = msg.SendAndReceive(proc);
  cout << endl << LongTest::compare(ret, 0) << endl;
  cout << endl << LongTest::compare(msg.CallType(), DDM_RETURN_OK) << endl;
  result = _driverList;
  expected = DDM_NULL_BUS_NAME;
  cout << endl << StringTest::compare(result, expected) << endl;
  delete _driverList;

  //------------- FIND DRIVER INFO
  IDriverInfo *driverInfo = new DriverInfo();
  bool retBool = DriverInfo::RemoteCopy(*driverInfo, proc, DRIVER_NAME);
  cout << endl << BoolTest::compare(retBool, true) << endl;
  result = driverInfo->Name();
  expected = DRIVER_NAME;
  cout << endl << StringTest::compare(result, expected) << endl;
  result = driverInfo->BusOwner();
  expected = "(null)";
  cout << endl << StringTest::compare(result, expected) << endl;

  //------------- FIND BUS INFO
  msg.CallType() = DDM_FIND_BUS_INFO;
  msg.AddressSize() = strlen(DDM_NULL_BUS_NAME);
  msg.SetAddress(DDM_NULL_BUS_NAME);
  ret = msg.SendAndReceive(proc);
  cout << endl << LongTest::compare(ret, 0) << endl;
  cout << endl << LongTest::compare(msg.CallType(), DDM_NEXT) << endl;

  _driverList = new char[msg.AddressSize()];
  memset(_driverList, 0, msg.AddressSize()*sizeof(char));
  msg.SetAddress(_driverList);
  ret = msg.SendAndReceive(proc);
  cout << endl << LongTest::compare(ret, 0) << endl;
  cout << endl << LongTest::compare(msg.CallType(), DDM_RETURN_OK) << endl;
  result = _driverList;
  expected = DRIVER_NAME;
  cout << endl << StringTest::compare(result, expected) << endl;
  delete _driverList;

  //------------- UNREGISTER DRIVER
  msg.CallType() = DDM_UNREGISTER;
  msg.AddressSize() = strlen(DRIVER_NAME);
  msg.SetAddress((char*)DRIVER_NAME);
  ret = msg.SendAndReceive(proc);
  cout << endl << LongTest::compare(ret, 0) << endl;
  cout << endl << LongTest::compare(msg.CallType(), DDM_RETURN_OK) << endl;

  //------------- ENUMERATE DRIVERS
  msg.CallType() = DDM_ENUMERATE_DRIVERS;
  ret = msg.SendAndReceive(proc);
  cout << endl << LongTest::compare(ret, 0) << endl;
  cout << endl << LongTest::compare(msg.CallType(), DDM_RETURN_OK) << endl;

  //------------- ENUMERATE BUSSES
  msg.CallType() = DDM_ENUMERATE_BUSSES;
  ret = msg.SendAndReceive(proc);
  cout << endl << LongTest::compare(ret, 0) << endl;
  cout << endl << LongTest::compare(msg.CallType(), DDM_RETURN_OK) << endl;

  return 0;
}
