#ifndef ELEMENTNOTINLISTEXCEPTION_H
#define ELEMENTNOTINLISTEXCEPTION_H
#include <string>
#include "Exception.h"

class ElementNotInListException : public Exception{
    public:
        virtual std::string getMessage() const;
};




#endif