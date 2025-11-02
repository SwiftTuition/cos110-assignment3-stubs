#ifndef LIST_CPP
#define LIST_CPP

#include "List.h"

template <class T>
List<T>::~List() {}

template <class T>
std::ostream& operator<<(std::ostream& out, const List<T>& list) {
    return list.print(out);
}

template <class T>
template <class U>
bool List<T>::operator==(const U& rhs) const {
    return true;  // Stub
}

#endif
