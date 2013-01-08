#ifndef _EXCEPTIONS_HPP_
#define _EXCEPTIONS_HPP_

#include <exception>

#define THROW(E, I) throw E(__func__, I)

namespace SymbolX
{
  /// @brief Base exception class.
  class BaseError : public std::exception
  {
  protected:
    /// @brief Reason for the exception.
    std::string _reason;

  public:
    /// @brief Constructor.
    /// @param throwingFunction Function that threw the exception.
    /// @param reason Reason exception was thrown.
    BaseError(const std::string &throwingFunction,
	      const std::string &reason) :
      exception(),
      _reason("in " + throwingFunction + "(): " + reason)
    {
    }

    /// @brief Destructor.
    virtual ~BaseError() throw()
    {
    }

    /// @brief Describes the reason the exception was thrown.
    /// @return Reason exception was thrown.
    virtual const char *what() const throw()
    {
      return _reason.c_str();
    }
  };

  /// @brief Raised when no file exists.
  class NoFileError : public BaseError
  {
  public:
    /// @brief Constructor.
    /// @param throwingFunction Function that threw the exception.
    /// @param fileName File name causing the problem.
    NoFileError(const std::string &throwingFunction,
		const std::string &fileName) :
      BaseError(throwingFunction, "no file named " + fileName)
    {
    }

    /// @brief Destructor.
    virtual ~NoFileError() throw()
    {
    }
  };

  /// @brief Raised when a bad key is given.
  class BadKeyError : public BaseError
  {
  public:
    /// @brief Constructor.
    /// @param throwingFunction Function that threw the exception.
    /// @param key Key causing the problem.
    BadKeyError(const std::string &throwingFunction,
		const std::string &key) :
      BaseError(throwingFunction, "bad key: " + key)
    {
    }

    /// @brief Destructor.
    virtual ~BadKeyError() throw()
    {
    }
  };
}

#endif
