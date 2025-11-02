#ifndef DLLIST_CPP
#define DLLIST_CPP

#include "DLList.h"

template <class T>
DLList<T>::DLList() : head(NULL) {}

template <class T>
DLList<T>::~DLList() {}

template <class T>
DLList<T>& DLList<T>::operator+=(T& data) {
    return *this;
}

template <class T>
DLList<T>& DLList<T>::operator-=(T& data) {
    return *this;
}

template <class T>
const T& DLList<T>::operator[](int index) const {
    static T* dummy = NULL;
    return *dummy;
}

template <class T>
T& DLList<T>::operator[](int index) {
    static T* dummy = NULL;
    return *dummy;
}

template <class T>
DLList<T>* DLList<T>::clone() {
    return NULL;
}

template <class T>
DLList<T>::operator int() const {
    return 0;
}

template <class T>
std::ostream& DLList<T>::print(std::ostream& out) const {
    return out;
}

#endif
