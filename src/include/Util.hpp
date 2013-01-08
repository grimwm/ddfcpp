#ifndef UTIL_HPP__
#define UTIL_HPP__

#include <string>

#define CONST_CHAR_TO_CHAR(data) \
  reinterpret_cast<char*>(reinterpret_cast<long>(data))

namespace SymbolX
{
  inline std::string getDirectorySeparator()
  {
#if defined(_WIN32) || defined(__MSDOS__) || defined(__CYGWIN__)
    return "\\";
#else
    return "/";
#endif
  }

  std::string getBasePath(const std::string &fullPath)
  {
    std::string separator = getDirectorySeparator();
    std::string::size_type loc = fullPath.find_last_of(separator);
    return fullPath.substr(0, loc);
  }

  std::string getFilePath(const std::string &fullPath)
  {
    std::string separator = getDirectorySeparator();
    std::string::size_type loc = fullPath.find_last_of(separator);
    return fullPath.substr(loc+1);
  }
}

#endif
