#ifndef QUEUE_CPP
#define QUEUE_CPP

#include "Queue.h"

template <class T>
Queue<T>::Queue() : front(NULL), rear(NULL) {}

template <class T>
Queue<T>::~Queue() {}

template <class T>
Queue<T>& Queue<T>::operator+=(T& data) {
    return *this;
}

template <class T>
Queue<T>& Queue<T>::operator-=(T& data) {
    return *this;
}

template <class T>
const T& Queue<T>::operator[](int index) const {
    static T* dummy = NULL;
    return *dummy;
}

template <class T>
T& Queue<T>::operator[](int index) {
    static T* dummy = NULL;
    return *dummy;
}

template <class T>
Queue<T>* Queue<T>::clone() {
    return NULL;
}

template <class T>
Queue<T>::operator int() const {
    return 0;
}

template <class T>
std::ostream& Queue<T>::print(std::ostream& out) const {
    return out;
}

#endif
