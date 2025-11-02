#ifndef PRINTER_CPP
#define PRINTER_CPP

#include "Printer.h"

template<template <class> class Iterable, class T>
Printer<Iterable, T>* Printer<Iterable, T>::printer = NULL;

template<template <class> class Iterable, class T>
int Printer<Iterable, T>::numberOfRequests = 0;

template<template <class> class Iterable, class T>
Printer<Iterable, T>::Printer() {}

template<template <class> class Iterable, class T>
Printer<Iterable, T>& Printer<Iterable, T>::requestPrinter() {
    static Printer<Iterable, T> dummy;
    return dummy;
}

template<template <class> class Iterable, class T>
void Printer<Iterable, T>::returnPrinter() {}

template<template <class> class Iterable, class T>
void Printer<Iterable, T>::insertDocument(T& data) {}

template<template <class> class Iterable, class T>
void Printer<Iterable, T>::printToStream(std::ostream& out) {}

template<template <class> class Iterable, class T>
void Printer<Iterable, T>::printToFile(std::fstream& f) {}

template<template <class> class Iterable, class T>
int Printer<Iterable, T>::numberOfDocuments() {
    return 0;
}

template<template <class> class Iterable, class T>
bool Printer<Iterable, T>::isInQueue(T& data) {
    return false;
}

#endif
