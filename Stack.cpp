#ifndef STACK_CPP
#define STACK_CPP

#include "Stack.h"

template <class T>
Stack<T>::Stack() : top(NULL) {}

template <class T>
Stack<T>::~Stack() {}

template <class T>
Stack<T>& Stack<T>::operator+=(T& data) {
    return *this;
}

template <class T>
Stack<T>& Stack<T>::operator-=(T& data) {
    return *this;
}

template <class T>
const T& Stack<T>::operator[](int index) const {
    static T* dummy = NULL;
    return *dummy;
}

template <class T>
T& Stack<T>::operator[](int index) {
    static T* dummy = NULL;
    return *dummy;
}

template <class T>
Stack<T>* Stack<T>::clone() {
    return NULL;
}

template <class T>
Stack<T>::operator int() const {
    return 0;
}

template <class T>
std::ostream& Stack<T>::print(std::ostream& out) const {
    return out;
}

#endif
