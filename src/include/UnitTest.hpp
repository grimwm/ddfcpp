#ifndef _UNIT_TEST_HPP_
#define _UNIT_TEST_HPP_

#include <string>
#include <cstdio>

namespace SymbolX
{
  static unsigned timesTestCalled = 0;
  const size_t UNSIGNED_STRING_REPRESENTATION = sizeof(unsigned)*2+1;
  const size_t LONG_STRING_REPRESENTATION = sizeof(long)*2+1;

  inline static std::string _successfulTest()
  {
    char called[UNSIGNED_STRING_REPRESENTATION];
    snprintf(called, UNSIGNED_STRING_REPRESENTATION,
	     "%u", timesTestCalled);
    return "Test " + std::string(called) + " successful.";
  }

  template <typename _Type> class UnitTest;
  typedef UnitTest<std::string> StringTest;
  typedef UnitTest<bool> BoolTest;
  typedef UnitTest<unsigned> UnsignedTest;
  typedef UnitTest<long> LongTest;

  /// @brief Base unit test class that can be specialized by other classes
  ///	     in order to spit out information about particular tests.
  template <typename _Type> class UnitTest
  {
  public:
    /// @brief Compares two _Type objects to see if they match.
    /// @param lhs Left-hand-side of equality equation.
    /// @param rhs Right-hand-side of equality equation.
    /// @return Message indicating success or failure of comparison.
    inline static std::string compare(const _Type &lhs, const _Type &rhs)
    {
      ++timesTestCalled;
      if (lhs == rhs) {
	return _successfulTest();
      }
      else {
	return lhs + "\nNOT EQUAL TO\n" + rhs;
      }
    }
  };

  /// @brief Unit test class for booleans.
  template <> class UnitTest<bool>
  {
  public:
    /// @brief Compares two booleans to see if they match.
    /// @param lhs Left-hand-side of equality equation.
    /// @param rhs Right-hand-side of equality equation.
    /// @return Message indicating success or failure of comparison.
    inline static std::string compare(const bool &lhs, const bool &rhs)
    {
      ++timesTestCalled;
      if (lhs == rhs) {
	return _successfulTest();
      }
      else {
	std::string result = (lhs) ? "true" : "false";
	result += "\nNOT EQUAL TO\n";
	result += (rhs) ? "true" : "false";
	return result;
      }
    }
  };

  /// @brief Unit test class for unsigned integers.
  template <> class UnitTest<unsigned>
  {
  public:
    /// @brief Compares two unsigned integers to see if they match.
    /// @param lhs Left-hand-side of equality equation.
    /// @param rhs Right-hand-side of equality equation.
    /// @return Message indicating success or failure of comparison.
    inline static std::string compare(const unsigned &lhs, const unsigned &rhs)
    {
      ++timesTestCalled;
      if (lhs == rhs) {
	return _successfulTest();
      }
      else
        {
          char num[UNSIGNED_STRING_REPRESENTATION];
          snprintf(num, UNSIGNED_STRING_REPRESENTATION, "%u", lhs);
          std::string result = num;
          result += "\nNOT EQUAL TO\n";
          snprintf(num, UNSIGNED_STRING_REPRESENTATION, "%u", rhs);
          result += num;
          return result;
        }
    }
  };

  /// @brief Unit test class for long integers.
  template <> class UnitTest<long>
  {
  public:
    /// @brief Compares two long integers to see if they match.
    /// @param lhs Left-hand-side of equality equation.
    /// @param rhs Right-hand-side of equality equation.
    /// @return Message indicating success or failure of comparison.
    inline static std::string compare(const long &lhs, const long &rhs)
    {
      ++timesTestCalled;
      if (lhs == rhs) {
	return _successfulTest();
      }
      else {
	char num[LONG_STRING_REPRESENTATION];
	snprintf(num, LONG_STRING_REPRESENTATION, "%ld", lhs);
	std::string result = num;
	result += "\nNOT EQUAL TO\n";
	snprintf(num, LONG_STRING_REPRESENTATION, "%ld", rhs);
	result += num;
	return result;
      }
    }
  };
}

#endif
