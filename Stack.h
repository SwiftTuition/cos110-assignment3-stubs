#ifndef STACK_H
#define STACK_H
#include <string>
#include <iostream>
#include "List.h"
#include "InvalidIndexException.h"

template <class T>
struct StackNode{
    T data;
    StackNode<T>* next;
};

template <class T>
class Stack : public List<T>{
    private:
        StackNode<T>* top;

    public:
        Stack();
        virtual ~Stack();
        Stack<T>& operator+=(T& data);
        Stack<T>& operator-=(T& data);
        const T& operator[](int index) const;
        T& operator[](int index);
        Stack<T>* clone();
        operator int() const;

    protected:
        std::ostream& print(std::ostream& out) const;
};
#include "Stack.cpp"


#endif