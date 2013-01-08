#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>

#include "Memory.hpp"
#include "UnitTest.hpp"
#include "Types.hpp"

using namespace std;
using namespace SymbolX;

int main()
{
  char source[] = "test";
  unsigned long size = strlen(source)+1;
  char sink[size+1];

  cout << LongTest::compare(Memory::Copy(SELF_PROC,
					 reinterpret_cast<long>(&sink),
					 SELF_PROC,
					 reinterpret_cast<long>(&source),
					 size), 0) << endl;

  std::string result = sink;
  std::string expected = source;
  cout << endl << StringTest::compare(result, expected) << endl;
}
