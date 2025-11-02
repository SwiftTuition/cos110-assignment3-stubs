#ifndef ARRAY_CPP
#define ARRAY_CPP

#include "Array.h"

template <class T>
Array<T>::Array(int size) : data(NULL), size(0) {}

template <class T>
Array<T>::~Array() {}

template <class T>
int Array<T>::numElements() const {
    return 0;
}

template <class T>
Array<T>& Array<T>::operator+=(T& d) {
    return *this;
}

template <class T>
Array<T>& Array<T>::operator-=(T& d) {
    return *this;
}

template <class T>
const T& Array<T>::operator[](int index) const {
    static T* dummy = NULL;
    return *dummy;
}

template <class T>
T& Array<T>::operator[](int index) {
    static T* dummy = NULL;
    return *dummy;
}

template <class T>
Array<T>* Array<T>::clone() {
    return NULL;
}

template <class T>
Array<T>::operator int() const {
    return 0;
}

template <class T>
std::ostream& operator<<(std::ostream& out, const Array<T>& array) {
    return out;
}

template <class T>
template <class U>
bool Array<T>::operator==(const U& rhs) const {
    return false;
}

#endif
