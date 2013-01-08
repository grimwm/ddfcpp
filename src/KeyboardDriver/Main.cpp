#include "KeyboardDriver.hpp"

using namespace SymbolX;

int main()
{
  Driver *driver = new KeyboardDriver();
  driver->Run();
  return 0;
}
