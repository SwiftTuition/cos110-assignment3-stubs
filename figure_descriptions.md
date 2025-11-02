Of course. Here is a complete and accurate text-based transcription of all 18 figures from the COS110 Assignment 3 specification.

***

### **Figure 1: Class diagrams**

This is a transcription of the main UML class diagram, broken down by each class and struct shown.

**Printer Class**
```
+---------------------------------------------------+
| Printer<Iterable, T>                              |
|---------------------------------------------------|
| - printer: Printer<Iterable, T>*                  |
| - numberOfRequests: int                           |
| - printerQueue: Iterator<Iterable, T>             |
|---------------------------------------------------|
| + requestPrinter(): Printer<Iterable, T>&         |
| + returnPrinter(): void                           |
| + insertDocument(data: T&): void                  |
| + printToStream(out: ostream&): void              |
| + printToFile(f: fstream&): void                  |
| + numberOfDocuments(): int                        |
| + isInQueue(data: T&): bool                        |
| - Printer()                                       |
+---------------------------------------------------+
```

**Iterator Class**
```
+---------------------------------------------------+
| Iterator<Iterable, T>                             |
|---------------------------------------------------|
| - iterable: Iterable<T>*                          |
| - currentPosition: int                            |
|---------------------------------------------------|
| + Iterator()                                      |
| + operator++(i: int): Iterator<Iterable, T>&      |
| + operator++(): Iterator<Iterable, T>&            |
| + operator--(i: int): Iterator<Iterable, T>&      |
| + operator--(): Iterator<Iterable, T>&            |
| + operator T&()                                   |
| + setStart(): void                                |
| + setEnd(): void                                  |
| + isAtStart(): bool                               |
| + isAtEnd(): bool                                 |
| + operator+=(data: T&): Iterator<Iterable, T>&    |
| + operator-=(data: T&): Iterator<Iterable, T>&    |
+---------------------------------------------------+
```

**List Class (Abstract)**
```
+-----------------------------------------------------------+
| List<T>                                                   |
| Inherits from: Iterable<T>                                |
|-----------------------------------------------------------|
| + ~List()                                                 |
| + operator+=(data: T&): List<T>&                          |
| + operator-=(data: T&): List<T>&                          |
| + operator[](index: int): const T&                        |
| + operator[](index: int): T&                              |
| + operator int()                                          |
| + clone(): List<T>*                                       |
| + operator<<(out: ostream&, list: const List<U>&): ostream&|
| + operator==(rhs: const U&): bool                         |
| # print(out: ostream&): ostream&                          |
+-----------------------------------------------------------+
```

**Array Class**
```
+-------------------------------------------------------------+
| Array<T>                                                    |
| Inherits from: Iterable<T>                                  |
|-------------------------------------------------------------|
| - data: T**                                                 |
| - size: int                                                 |
|-------------------------------------------------------------|
| + Array(size: int = 1)                                      |
| + ~Array()                                                  |
| + numElements(): int                                        |
| + operator int()                                            |
| + operator+=(d: T&): Array<T>&                              |
| + operator-=(d: T&): Array<T>&                              |
| + operator[](index: int): const T&                          |
| + operator[](index: int): T&                                |
| + clone(): Array<T>*                                        |
| + operator<<(out: ostream&, array: const Array<U>&): ostream&|
| + operator==(rhs: const U&): bool                           |
+-------------------------------------------------------------+
```

**DLList Class**
```
+-------------------------------------------------+
| DLList<T>                                       |
| Inherits from: List<T>                          |
|-------------------------------------------------|
| - head: DLLNode<T>*                              |
|-------------------------------------------------|
| + DLList()                                      |
| + ~DLList()                                     |
| + operator+=(data: T&): DLList<T>&              |
| + operator-=(data: T&): DLList<T>&              |
| + operator[](index: int): const T&              |
| + operator[](index: int): T&                    |
| + clone(): DLList<T>*                           |
| + operator int()                                |
| # print(out: ostream&): ostream&                |
+-------------------------------------------------+
| Contains: DLLNode                               |
+-------------------------------------------------+
```

**DLLNode Struct**
```
+--------------------------+
| <<Struct>>               |
| DLLNode<U>               |
|--------------------------|
| + data: U                |
| + next: DLLNode<U>*      |
| + prev: DLLNode<U>*      |
+--------------------------+
```

**Queue Class**
```
+-------------------------------------------------+
| Queue<T>                                        |
| Inherits from: List<T>                          |
|-------------------------------------------------|
| - front: QueueNode<T>*                          |
| - rear: QueueNode<T>*                           |
|-------------------------------------------------|
| + Queue()                                       |
| + ~Queue()                                      |
| + operator+=(data: T&): Queue<T>&               |
| + operator-=(data: T&): Queue<T>&               |
| + operator[](index: int): const T&              |
| + operator[](index: int): T&                    |
| + clone(): Queue<T>*                            |
| + operator int()                                |
| # print(out: ostream&): ostream&                |
+-------------------------------------------------+
| Contains: QueueNode                             |
+-------------------------------------------------+
```

**QueueNode Struct**
```
+--------------------------+
| <<Struct>>               |
| QueueNode<U>             |
|--------------------------|
| + data: U                |
| + next: QueueNode<U>*    |
+--------------------------+
```

**Stack Class**
```
+-------------------------------------------------+
| Stack<T>                                        |
| Inherits from: List<T>                          |
|-------------------------------------------------|
| - top: StackNode<T>*                            |
|-------------------------------------------------|
| + Stack()                                       |
| + ~Stack()                                      |
| + operator+=(data: T&): Stack<T>&               |
| + operator-=(data: T&): Stack<T>&               |
| + operator[](index: int): const T&              |
| + operator[](index: int): T&                    |
| + clone(): Stack<T>*                            |
| + operator int()                                |
| # print(out: ostream&): ostream&                |
+-------------------------------------------------+
| Contains: StackNode                             |
+-------------------------------------------------+
```

**StackNode Struct**
```
+--------------------------+
| <<Struct>>               |
| StackNode<U>             |
|--------------------------|
| + data: U                |
| + next: StackNode<U>*    |
+--------------------------+
```

**Exception Class Hierarchy**
```
+-----------------------------------------------------------+
| Exception (Abstract)                                      |
|-----------------------------------------------------------|
| + ~Exception()                                            |
| + operator<<(out: ostream&, e: const Exception&): ostream& |
| + getMessage(): string                                    |
+-----------------------------------------------------------+
      ^
      | (Inheritance)
      +------------------------------------------------------------------+
      |                                                                  |
+-----------------------------------------------------------+      +---------------------------------+
| InvalidIndexException                                     |      | InvalidSizeException            |
|-----------------------------------------------------------|      |---------------------------------|
| - index: int                                              |      | - size: int                     |
| - isNull: bool                                            |      |---------------------------------|
|-----------------------------------------------------------|      | + InvalidSizeException(size: int) |
| + InvalidIndexException(index: int, isNull: bool = false) |      | + getMessage(): string          |
| + getMessage(): string                                    |      +---------------------------------+
+-----------------------------------------------------------+
      |
+---------------------------------+
| ElementNotInListException       |
|---------------------------------|
| + getMessage(): string          |
+---------------------------------+
      |
+---------------------------------+
| OutOfBoundsException            |
|---------------------------------|
| + getMessage(): string          |
+---------------------------------+
      |
+---------------------------------+
| PrinterNotInitialized           |
|---------------------------------|
| + getMessage(): string          |
+---------------------------------+
      |
+---------------------------------+
| TooManyPrintersDeleted          |
|---------------------------------|
| + getMessage(): string          |
+---------------------------------+
```

***

### **Figure 2: UML for Exception**
```
+-----------------------------------------------------------+
| Exception                                                 |
|-----------------------------------------------------------|
| + ~Exception()                                            |
| + operator<<(out: ostream&, e: const Exception&): ostream& |
| + getMessage(): string                                    |
+-----------------------------------------------------------+
```

***

### **Figure 3: UML for InvalidIndexException**
```
+-----------------------------------------------------------+
| InvalidIndexException                                     |
|-----------------------------------------------------------|
| - index: int                                              |
| - isNull: bool                                            |
|-----------------------------------------------------------|
| + InvalidIndexException(index: int, isNull: bool = false) |
| + getMessage(): string                                    |
+-----------------------------------------------------------+```

***

### **Figure 4: UML for InvalidSizeException**
```
+-------------------------------------+
| InvalidSizeException                |
|-------------------------------------|
| - size: int                         |
|-------------------------------------|
| + InvalidSizeException(size: int)   |
| + getMessage(): string              |
+-------------------------------------+
```

***

### **Figure 5: UML for ElementNotInListException**
```
+-----------------------------+
| ElementNotInListException   |
|-----------------------------|
| + getMessage(): string      |
+-----------------------------+
```

***

### **Figure 6: UML for OutOfBoundsException**```
+-----------------------------+
| OutOfBoundsException        |
|-----------------------------|
| + getMessage(): string      |
+-----------------------------+
```

***

### **Figure 7: UML for TooManyPrintersDeleted**
```
+-----------------------------+
| TooManyPrintersDeleted      |
|-----------------------------|
| + getMessage(): string      |
+-----------------------------+
```

***

### **Figure 8: UML for PrinterNotInitialized**
```
+-----------------------------+
| PrinterNotInitialized       |
|-----------------------------|
| + getMessage(): string      |
+-----------------------------+
```

***

### **Figure 9: UML for Array**
```
+-------------------------------------------------------------+
| Array<T>                                                    |
| Template Parameters: T: class, U: class                     |
|-------------------------------------------------------------|
| - data: T**                                                 |
| - size: int                                                 |
|-------------------------------------------------------------|
| + Array(size: int = 1)                                      |
| + ~Array()                                                  |
| + numElements(): int                                        |
| + operator int()                                            |
| + operator+=(d: T&): Array<T>&                              |
| + operator-=(d: T&): Array<T>&                              |
| + operator[](index: int): const T&                          |
| + operator[](index: int): T&                                |
| + clone(): Array<T>*                                        |
| + operator<<(out: ostream&, array: const Array<U>&): ostream&|
| + operator==(rhs: const U&): bool                           |
+-------------------------------------------------------------+
```

***

### **Figure 10: UML for List**
```
+-----------------------------------------------------------+
| List<T>                                                   |
| Template Parameters: T: class, U: class                   |
|-----------------------------------------------------------|
| + ~List()                                                 |
| + operator+=(data: T&): List<T>&                          |
| + operator-=(data: T&): List<T>&                          |
| + operator[](index: int): const T&                        |
| + operator[](index: int): T&                              |
| + operator int()                                          |
| + clone(): List<T>*                                       |
| + operator<<(out: ostream&, list: const List<U>&): ostream&|
| + operator==(rhs: const U&): bool                         |
| # print(out: ostream&): ostream&                          |
+-----------------------------------------------------------+
```

***

### **Figure 11: UML for DLList**
```
+---------------------------------------+
| DLList<T>                             |
| Template Parameter: T: class          |
|---------------------------------------|
| - head: DLLNode<T>*                    |
|---------------------------------------|
| + DLList()                            |
| + ~DLList()                           |
| + operator+=(data: T&): DLList<T>&    |
| + operator-=(data: T&): DLList<T>&    |
| + operator[](index: int): const T&    |
| + operator[](index: int): T&          |
| + clone(): DLList<T>*                 |
| + operator int()                      |
| # print(out: ostream&): ostream&      |
+---------------------------------------+
```

***

### **Figure 12: UML for DLLNode**
```
+--------------------------+
| <<Struct>>               |
| DLLNode<U>               |
| Template Parameter: U: class |
|--------------------------|
| + data: U                |
| + next: DLLNode<U>*      |
| + prev: DLLNode<U>*      |
+--------------------------+
```

***

### **Figure 13: UML for Queue**
```
+--------------------------------------+
| Queue<T>                             |
| Template Parameter: T: class         |
|--------------------------------------|
| - front: QueueNode<T>*               |
| - rear: QueueNode<T>*                |
|--------------------------------------|
| + Queue()                            |
| + ~Queue()                           |
| + operator+=(data: T&): Queue<T>&    |
| + operator-=(data: T&): Queue<T>&    |
| + operator[](index: int): const T&   |
| + operator[](index: int): T&         |
| + clone(): Queue<T>*                 |
| + operator int()                     |
| # print(out: ostream&): ostream&     |
+--------------------------------------+
```

***

### **Figure 14: UML for QueueNode**
```
+--------------------------+
| <<Struct>>               |
| QueueNode<U>             |
| Template Parameter: U: class |
|--------------------------|
| + data: U                |
| + next: QueueNode<U>*    |
+--------------------------+
```

***

### **Figure 15: UML for Stack**
```
+--------------------------------------+
| Stack<T>                             |
| Template Parameter: T: class         |
|--------------------------------------|
| - top: StackNode<T>*                 |
|--------------------------------------|
| + Stack()                            |
| + ~Stack()                           |
| + operator+=(data: T&): Stack<T>&    |
| + operator-=(data: T&): Stack<T>&    |
| + operator[](index: int): const T&   |
| + operator[](index: int): T&         |
| + clone(): Stack<T>*                 |
| + operator int()                     |
| # print(out: ostream&): ostream&     |
+--------------------------------------+
```

***

### **Figure 16: UML for StackNode**
```
+--------------------------+
| <<Struct>>               |
| StackNode<U>             |
| Template Parameter: U: class |
|--------------------------|
| + data: U                |
| + next: StackNode<U>*    |
+--------------------------+
```

***

### **Figure 17: UML for Iterator**
```
+---------------------------------------------------+
| Iterator<Iterable, T>                             |
| Template Preamble:                                |
| template<template <class> class Iterable, class T>|
|---------------------------------------------------|
| - iterable: Iterable<T>*                          |
| - currentPosition: int                            |
|---------------------------------------------------|
| + Iterator()                                      |
| + operator++(i: int): Iterator<Iterable, T>&      |
| + operator++(): Iterator<Iterable, T>&            |
| + operator--(i: int): Iterator<Iterable, T>&      |
| + operator--(): Iterator<Iterable, T>&            |
| + operator T&()                                   |
| + setStart(): void                                |
| + setEnd(): void                                  |
| + isAtStart(): bool                               |
| + isAtEnd(): bool                                 |
| + operator+=(data: T&): Iterator<Iterable, T>&    |
| + operator-=(data: T&): Iterator<Iterable, T>&    |
+---------------------------------------------------+
```

***

### **Figure 18: UML for Printer**
```
+---------------------------------------------------+
| Printer<Iterable, T>                              |
| Template Preamble:                                |
| template<template <class> class Iterable, class T>|
|---------------------------------------------------|
| - printer: Printer<Iterable, T>*                  |
| - numberOfRequests: int                           |
| - printerQueue: Iterator<Iterable, T>             |
|---------------------------------------------------|
| + requestPrinter(): Printer<Iterable, T>&         |
| + returnPrinter(): void                           |
| + insertDocument(data: T&): void                  |
| + printToStream(out: ostream&): void              |
| + printToFile(f: fstream&): void                  |
| + numberOfDocuments(): int                        |
| + isInQueue(data: T&): bool                        |
| - Printer()                                       |
+---------------------------------------------------+
```