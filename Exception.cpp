#include "Exception.h"

Exception::~Exception() {}

std::ostream& operator<<(std::ostream& out, const Exception& e) {
    return out;
}
