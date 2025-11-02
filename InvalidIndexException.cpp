#include "InvalidIndexException.h"

InvalidIndexException::InvalidIndexException(int index, bool isNull) {
    this->index = index;
    this->isNull = isNull;
}

std::string InvalidIndexException::getMessage() const {
    return "";
}
