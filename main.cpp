#include <iostream>
#include <fstream>
#include <sstream>
#include "Exception.h"
#include "InvalidIndexException.h"
#include "InvalidSizeException.h"
#include "ElementNotInListException.h"
#include "OutOfBoundsException.h"
#include "TooManyPrintersDeleted.h"
#include "PrinterNotInitialized.h"
#include "Array.h"
#include "DLList.h"
#include "Queue.h"
#include "Stack.h"
#include "Iterator.h"
#include "Printer.h"

void testExceptions() {
    std::cout << "=== Testing Exceptions ===" << std::endl;

    // Test InvalidIndexException
    try {
        InvalidIndexException e1(5, false);
        std::cout << "InvalidIndexException (not null): " << e1.getMessage() << std::endl;

        InvalidIndexException e2(10, true);
        std::cout << "InvalidIndexException (null): " << e2.getMessage() << std::endl;
    } catch (...) {
        std::cout << "Unexpected exception in InvalidIndexException test" << std::endl;
    }

    // Test InvalidSizeException
    try {
        InvalidSizeException e(-5);
        std::cout << "InvalidSizeException: " << e.getMessage() << std::endl;
    } catch (...) {
        std::cout << "Unexpected exception in InvalidSizeException test" << std::endl;
    }

    // Test ElementNotInListException
    try {
        ElementNotInListException e;
        std::cout << "ElementNotInListException: " << e.getMessage() << std::endl;
    } catch (...) {
        std::cout << "Unexpected exception in ElementNotInListException test" << std::endl;
    }

    // Test OutOfBoundsException
    try {
        OutOfBoundsException e;
        std::cout << "OutOfBoundsException: " << e.getMessage() << std::endl;
    } catch (...) {
        std::cout << "Unexpected exception in OutOfBoundsException test" << std::endl;
    }

    // Test TooManyPrintersDeleted
    try {
        TooManyPrintersDeleted e;
        std::cout << "TooManyPrintersDeleted: " << e.getMessage() << std::endl;
    } catch (...) {
        std::cout << "Unexpected exception in TooManyPrintersDeleted test" << std::endl;
    }

    // Test PrinterNotInitialized
    try {
        PrinterNotInitialized e;
        std::cout << "PrinterNotInitialized: " << e.getMessage() << std::endl;
    } catch (...) {
        std::cout << "Unexpected exception in PrinterNotInitialized test" << std::endl;
    }

    std::cout << std::endl;
}

void testArray() {
    std::cout << "=== Testing Array ===" << std::endl;

    // Test constructor
    Array<int> arr(5);
    std::cout << "Array size: " << (int)arr << std::endl;
    std::cout << "Num elements: " << arr.numElements() << std::endl;

    // Test operator+=
    int val1 = 10, val2 = 20, val3 = 30;
    arr += val1;
    arr += val2;
    arr += val3;
    std::cout << "After adding 3 elements: " << arr << std::endl;
    std::cout << "Num elements: " << arr.numElements() << std::endl;

    // Test operator[] access
    try {
        std::cout << "arr[0] = " << arr[0] << std::endl;
        std::cout << "arr[1] = " << arr[1] << std::endl;
    } catch (InvalidIndexException& e) {
        std::cout << "Exception: " << e.getMessage() << std::endl;
    }

    // Test auto-resize (double when full)
    int val4 = 40, val5 = 50, val6 = 60;
    arr += val4;
    arr += val5;
    arr += val6;  // This should trigger resize
    std::cout << "After adding 6 elements (resize): " << arr << std::endl;
    std::cout << "New size: " << (int)arr << std::endl;

    // Test operator-=
    arr -= val2;
    std::cout << "After removing 20: " << arr << std::endl;
    std::cout << "Num elements: " << arr.numElements() << std::endl;

    // Test exception on invalid removal
    try {
        int notInArray = 999;
        arr -= notInArray;
    } catch (ElementNotInListException& e) {
        std::cout << "Caught expected exception: " << e.getMessage() << std::endl;
    }

    // Test invalid index access
    try {
        int invalid = arr[100];
        (void)invalid;
    } catch (InvalidIndexException& e) {
        std::cout << "Caught expected exception: " << e.getMessage() << std::endl;
    }

    // Test NULL access
    try {
        int nullAccess = arr[4];  // This should be NULL
        (void)nullAccess;
    } catch (InvalidIndexException& e) {
        std::cout << "Caught NULL access exception: " << e.getMessage() << std::endl;
    }

    // Test clone
    Array<int>* arrClone = arr.clone();
    std::cout << "Clone: " << *arrClone << std::endl;

    // Test equality
    if (arr == *arrClone) {
        std::cout << "Array equals its clone: TRUE" << std::endl;
    }

    delete arrClone;

    // Test invalid size exception
    try {
        Array<int> invalidArr(-1);
    } catch (InvalidSizeException& e) {
        std::cout << "Caught invalid size: " << e.getMessage() << std::endl;
    }

    std::cout << std::endl;
}

void testDLList() {
    std::cout << "=== Testing DLList ===" << std::endl;

    DLList<int> list;
    std::cout << "Initial size: " << (int)list << std::endl;

    // Test sorted insertion (ascending order)
    int val1 = 50, val2 = 20, val3 = 80, val4 = 10, val5 = 60;
    list += val1;
    list += val2;
    list += val3;
    list += val4;
    list += val5;

    std::cout << "After inserting 50,20,80,10,60 (sorted): " << list << std::endl;
    std::cout << "Size: " << (int)list << std::endl;

    // Test operator[] access
    try {
        std::cout << "list[0] = " << list[0] << std::endl;
        std::cout << "list[2] = " << list[2] << std::endl;
        std::cout << "list[4] = " << list[4] << std::endl;
    } catch (InvalidIndexException& e) {
        std::cout << "Exception: " << e.getMessage() << std::endl;
    }

    // Test operator-=
    list -= val3;  // Remove 80
    std::cout << "After removing 80: " << list << std::endl;
    std::cout << "Size: " << (int)list << std::endl;

    // Test exception on invalid removal
    try {
        int notInList = 999;
        list -= notInList;
    } catch (ElementNotInListException& e) {
        std::cout << "Caught expected exception: " << e.getMessage() << std::endl;
    }

    // Test invalid index
    try {
        int invalid = list[100];
        (void)invalid;
    } catch (InvalidIndexException& e) {
        std::cout << "Caught invalid index: " << e.getMessage() << std::endl;
    }

    // Test clone
    DLList<int>* listClone = list.clone();
    std::cout << "Clone: " << *listClone << std::endl;

    delete listClone;

    std::cout << std::endl;
}

void testQueue() {
    std::cout << "=== Testing Queue (FIFO) ===" << std::endl;

    Queue<int> queue;
    std::cout << "Initial size: " << (int)queue << std::endl;

    // Test enqueue
    int val1 = 10, val2 = 20, val3 = 30, val4 = 40;
    queue += val1;
    queue += val2;
    queue += val3;
    queue += val4;

    std::cout << "After enqueuing 10,20,30,40: " << queue << std::endl;
    std::cout << "Size: " << (int)queue << std::endl;

    // Test operator[] access
    try {
        std::cout << "queue[0] (front) = " << queue[0] << std::endl;
        std::cout << "queue[3] (rear) = " << queue[3] << std::endl;
    } catch (InvalidIndexException& e) {
        std::cout << "Exception: " << e.getMessage() << std::endl;
    }

    // Test dequeue
    int dequeued;
    queue -= dequeued;
    std::cout << "Dequeued: " << dequeued << " (should be 10)" << std::endl;
    std::cout << "After dequeue: " << queue << std::endl;
    std::cout << "Size: " << (int)queue << std::endl;

    queue -= dequeued;
    std::cout << "Dequeued: " << dequeued << " (should be 20)" << std::endl;
    std::cout << "After dequeue: " << queue << std::endl;

    // Test clone
    Queue<int>* queueClone = queue.clone();
    std::cout << "Clone: " << *queueClone << std::endl;

    delete queueClone;

    // Test invalid index
    try {
        int invalid = queue[100];
        (void)invalid;
    } catch (InvalidIndexException& e) {
        std::cout << "Caught invalid index: " << e.getMessage() << std::endl;
    }

    std::cout << std::endl;
}

void testStack() {
    std::cout << "=== Testing Stack (LIFO) ===" << std::endl;

    Stack<int> stack;
    std::cout << "Initial size: " << (int)stack << std::endl;

    // Test push
    int val1 = 10, val2 = 20, val3 = 30, val4 = 40;
    stack += val1;
    stack += val2;
    stack += val3;
    stack += val4;

    std::cout << "After pushing 10,20,30,40: " << stack << std::endl;
    std::cout << "Size: " << (int)stack << std::endl;

    // Test operator[] access
    try {
        std::cout << "stack[0] (top) = " << stack[0] << std::endl;
        std::cout << "stack[3] (bottom) = " << stack[3] << std::endl;
    } catch (InvalidIndexException& e) {
        std::cout << "Exception: " << e.getMessage() << std::endl;
    }

    // Test pop
    int popped;
    stack -= popped;
    std::cout << "Popped: " << popped << " (should be 40)" << std::endl;
    std::cout << "After pop: " << stack << std::endl;
    std::cout << "Size: " << (int)stack << std::endl;

    stack -= popped;
    std::cout << "Popped: " << popped << " (should be 30)" << std::endl;
    std::cout << "After pop: " << stack << std::endl;

    // Test clone
    Stack<int>* stackClone = stack.clone();
    std::cout << "Clone: " << *stackClone << std::endl;

    delete stackClone;

    // Test invalid index
    try {
        int invalid = stack[100];
        (void)invalid;
    } catch (InvalidIndexException& e) {
        std::cout << "Caught invalid index: " << e.getMessage() << std::endl;
    }

    std::cout << std::endl;
}

void testIterator() {
    std::cout << "=== Testing Iterator ===" << std::endl;

    // Iterator uses default constructor and operator+= to build collection
    Iterator<Array, int> it;

    int val1 = 10, val2 = 20, val3 = 30;
    it += val1;
    it += val2;
    it += val3;

    std::cout << "Iterator setStart()" << std::endl;
    it.setStart();

    std::cout << "Iterating forward:" << std::endl;
    while (!it.isAtEnd()) {
        try {
            int& value = it;
            std::cout << "  Value: " << value << std::endl;
            ++it;
        } catch (OutOfBoundsException& e) {
            std::cout << "  Caught OutOfBoundsException" << std::endl;
            break;
        } catch (InvalidIndexException& e) {
            std::cout << "  Caught InvalidIndexException (NULL element)" << std::endl;
            ++it;
        }
    }

    std::cout << "Iterator setEnd()" << std::endl;
    it.setEnd();

    std::cout << "Iterating backward:" << std::endl;
    while (!it.isAtStart()) {
        try {
            --it;
            int& value = it;
            std::cout << "  Value: " << value << std::endl;
        } catch (OutOfBoundsException& e) {
            std::cout << "  Caught OutOfBoundsException" << std::endl;
            break;
        } catch (InvalidIndexException& e) {
            std::cout << "  Caught InvalidIndexException (NULL element)" << std::endl;
        }
    }

    std::cout << std::endl;
}

void testPrinter() {
    std::cout << "=== Testing Printer (Singleton) ===" << std::endl;

    // Request printer (static method) - Printer<Array, int> uses Array to store int documents
    Printer<Array, int>& printer1 = Printer<Array, int>::requestPrinter();
    std::cout << "Printer 1 requested" << std::endl;

    Printer<Array, int>& printer2 = Printer<Array, int>::requestPrinter();
    std::cout << "Printer 2 requested (should be same instance)" << std::endl;

    // Add int documents to queue (instance methods)
    int doc1 = 100, doc2 = 200, doc3 = 300;

    printer1.insertDocument(doc1);
    printer1.insertDocument(doc2);
    printer1.insertDocument(doc3);

    std::cout << "Number of documents: " << printer1.numberOfDocuments() << std::endl;

    // Test isInQueue
    if (printer1.isInQueue(doc1)) {
        std::cout << "doc1 is in queue: TRUE" << std::endl;
    }

    // Print to stream
    std::cout << "Printing to stream:" << std::endl;
    printer1.printToStream(std::cout);

    // Print to file
    std::fstream outFile("printer_output.txt", std::ios::out);
    if (outFile.is_open()) {
        printer1.printToFile(outFile);
        outFile.close();
        std::cout << "Printed to file: printer_output.txt" << std::endl;
    }

    // Return printers (instance methods)
    printer1.returnPrinter();
    std::cout << "Printer 1 returned" << std::endl;

    printer2.returnPrinter();
    std::cout << "Printer 2 returned (should delete instance)" << std::endl;

    // Test returning too many times
    try {
        Printer<Array, int>& printer3 = Printer<Array, int>::requestPrinter();
        printer3.returnPrinter();
        printer3.returnPrinter();  // Should throw
    } catch (TooManyPrintersDeleted& e) {
        std::cout << "Caught expected exception: " << e.getMessage() << std::endl;
    }

    std::cout << std::endl;
}

void testEdgeCases() {
    std::cout << "=== Testing Edge Cases ===" << std::endl;

    // Empty queue dequeue
    Queue<int> emptyQueue;
    int dummy;
    emptyQueue -= dummy;  // Should not crash
    std::cout << "Empty queue dequeue: no crash" << std::endl;

    // Empty stack pop
    Stack<int> emptyStack;
    emptyStack -= dummy;  // Should not crash
    std::cout << "Empty stack pop: no crash" << std::endl;

    // Single element operations
    Array<int> singleArr(1);
    int single = 999;
    singleArr += single;
    std::cout << "Single element array: " << singleArr << std::endl;

    // Array shrinking
    Array<int> shrinkArr(8);
    int a = 1, b = 2, c = 3, d = 4;
    shrinkArr += a;
    shrinkArr += b;
    shrinkArr += c;
    shrinkArr += d;
    std::cout << "Before shrinking (size " << (int)shrinkArr << "): " << shrinkArr << std::endl;

    shrinkArr -= a;
    shrinkArr -= b;
    shrinkArr -= c;
    std::cout << "After removing 3 elements (size " << (int)shrinkArr << "): " << shrinkArr << std::endl;

    std::cout << std::endl;
}

int main() {
    std::cout << "========================================" << std::endl;
    std::cout << "    COS 110 Assignment 3 - Testing     " << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << std::endl;

    testExceptions();
    testArray();
    testDLList();
    testQueue();
    testStack();
    testIterator();
    testPrinter();
    testEdgeCases();

    std::cout << "========================================" << std::endl;
    std::cout << "      All tests completed!              " << std::endl;
    std::cout << "========================================" << std::endl;

    return 0;
}
