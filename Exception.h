#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <string>
#include <iostream>


class Exception{
    public:
       virtual ~Exception();
       friend std::ostream& operator<<(std::ostream& out, const Exception& e);
       virtual std::string getMessage() const = 0;
};

#endif