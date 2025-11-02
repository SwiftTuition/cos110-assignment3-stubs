#ifndef ITERATOR_CPP
#define ITERATOR_CPP

#include "Iterator.h"

template<template <class> class Iterable, class T>
Iterator<Iterable, T>::Iterator() : currentPosition(0) {}

template<template <class> class Iterable, class T>
Iterator<Iterable, T>& Iterator<Iterable, T>::operator++(int i) {
    return *this;
}

template<template <class> class Iterable, class T>
Iterator<Iterable, T>& Iterator<Iterable, T>::operator++() {
    return *this;
}

template<template <class> class Iterable, class T>
Iterator<Iterable, T>& Iterator<Iterable, T>::operator--(int i) {
    return *this;
}

template<template <class> class Iterable, class T>
Iterator<Iterable, T>& Iterator<Iterable, T>::operator--() {
    return *this;
}

template<template <class> class Iterable, class T>
Iterator<Iterable, T>::operator T&() {
    static T* dummy = NULL;
    return *dummy;
}

template<template <class> class Iterable, class T>
void Iterator<Iterable, T>::setStart() {}

template<template <class> class Iterable, class T>
void Iterator<Iterable, T>::setEnd() {}

template<template <class> class Iterable, class T>
bool Iterator<Iterable, T>::isAtStart() const {
    return false;
}

template<template <class> class Iterable, class T>
bool Iterator<Iterable, T>::isAtEnd() const {
    return false;
}

template<template <class> class Iterable, class T>
Iterator<Iterable, T>& Iterator<Iterable, T>::operator+=(T& data) {
    return *this;
}

template<template <class> class Iterable, class T>
Iterator<Iterable, T>& Iterator<Iterable, T>::operator-=(T& data) {
    return *this;
}

#endif
