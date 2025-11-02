#include "InvalidSizeException.h"

InvalidSizeException::InvalidSizeException(int size) : size(size) {}

std::string InvalidSizeException::getMessage() const {
    return "";
}
