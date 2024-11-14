#include "exceptions.h"

BasicException::BasicException(const char* message) : std::exception(message) {}

InvalidSaveFileException::InvalidSaveFileException() :
    BasicException("Error ocurred while reading from file") {}

InvalidSaveFileException::InvalidSaveFileException(const char* message) :
    BasicException(message) {}
