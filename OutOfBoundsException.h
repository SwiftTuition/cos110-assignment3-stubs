#ifndef OUTOFBOUNDEXCEPTION_H
#define OUTOFBOUNDEXCEPTION_H
#include <string>
#include "Exception.h"

class OutOfBoundsException : public Exception{
    public:
        virtual std::string getMessage() const;
};



#endif