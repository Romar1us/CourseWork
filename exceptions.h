#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>

class BasicException : public std::exception
{
public:
    BasicException() = delete;
    BasicException(const char* message);
};

class InvalidSaveFileException :  public BasicException
{
public:
    InvalidSaveFileException();
    InvalidSaveFileException(const char* message);

};

#endif // EXCEPTIONS_H
