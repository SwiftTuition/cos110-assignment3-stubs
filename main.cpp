/**
 * ============================================================================
 * SWIFT TUITION'S STUBBED MAIN
 * ============================================================================
 *
 * ⚠️ CRITICAL WARNING ⚠️
 *
 * This is NOT the same main.cpp that was used in the actual FitchFork
 * submission! This is a SIMPLIFIED STUB for demonstration purposes only.
 *
 * ❌ DO NOT SUBMIT THIS MAIN TO FITCHFORK ❌
 *
 * This stubbed main.cpp has already been uploaded to FitchFork as part of
 * the testing process. If you submit code with this exact main, FitchFork
 * may flag it as a duplicate submission.
 *
 * ✅ YOU MUST CREATE YOUR OWN main.cpp ✅
 *
 * Use this as a REFERENCE for:
 * - How to include the necessary headers
 * - Basic syntax for using the classes
 * - Simple examples of each class
 *
 * But you MUST write your own comprehensive test suite!
 *
 * ============================================================================
 */

#include <iostream>
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

using namespace std;

/**
 * Basic example of testing exceptions
 * This is INCOMPLETE - you need to add comprehensive tests!
 */
void demonstrateExceptions() {
    cout << "\n=== Exception Demonstration ===" << endl;

    try {
        // Example: InvalidIndexException
        InvalidIndexException e(5, false);
        cout << "InvalidIndexException message: " << e.getMessage() << endl;
    } catch (Exception& e) {
        cout << "Caught: " << e.getMessage() << endl;
    }

    // TODO: Add tests for other exceptions
    // - InvalidSizeException
    // - ElementNotInListException
    // - OutOfBoundsException
    // - TooManyPrintersDeleted
    // - PrinterNotInitialized
}

/**
 * Basic example of testing Array
 * This is INCOMPLETE - you need to add comprehensive tests!
 */
void demonstrateArray() {
    cout << "\n=== Array Demonstration ===" << endl;

    // Create an array with initial capacity
    Array<int> arr(5);
    cout << "Created array with capacity: " << (int)arr << endl;

    // Add some elements
    int val1 = 10, val2 = 20;
    arr += val1;
    arr += val2;
    cout << "After adding elements: " << arr << endl;

    // TODO: Add comprehensive tests for:
    // - operator+=, operator-=
    // - operator[]
    // - Auto-resizing (doubling when full)
    // - Auto-shrinking (halving when less than half full)
    // - clone()
    // - Edge cases (empty, full, invalid indices)
}

/**
 * Basic example of testing DLList
 * This is INCOMPLETE - you need to add comprehensive tests!
 */
void demonstrateDLList() {
    cout << "\n=== DLList Demonstration ===" << endl;

    // Create a doubly-linked list
    DLList<int> list;

    // Add elements (should insert in sorted order)
    int val1 = 30, val2 = 10, val3 = 20;
    list += val1;
    list += val2;
    list += val3;
    cout << "After adding 30, 10, 20 (should be sorted): " << list << endl;

    // TODO: Add comprehensive tests for:
    // - Sorted insertion
    // - operator-= (removal)
    // - operator[] (access by index)
    // - clone()
    // - Edge cases (empty list, duplicate values, removing non-existent)
}

/**
 * Basic example of testing Queue
 * This is INCOMPLETE - you need to add comprehensive tests!
 */
void demonstrateQueue() {
    cout << "\n=== Queue Demonstration ===" << endl;

    // Create a queue
    Queue<int> q;

    // Enqueue some elements
    int val1 = 100, val2 = 200;
    q += val1;
    q += val2;
    cout << "After enqueueing: " << q << endl;

    // TODO: Add comprehensive tests for:
    // - operator+= (enqueue)
    // - operator-= (dequeue)
    // - operator[] (access by index)
    // - clone()
    // - FIFO behavior verification
}

/**
 * Basic example of testing Stack
 * This is INCOMPLETE - you need to add comprehensive tests!
 */
void demonstrateStack() {
    cout << "\n=== Stack Demonstration ===" << endl;

    // Create a stack
    Stack<int> s;

    // Push some elements
    int val1 = 5, val2 = 10;
    s += val1;
    s += val2;
    cout << "After pushing: " << s << endl;

    // TODO: Add comprehensive tests for:
    // - operator+= (push)
    // - operator-= (pop)
    // - operator[] (access by index)
    // - clone() - MUST preserve order!
    // - LIFO behavior verification
}

/**
 * Basic example of testing Iterator
 * This is INCOMPLETE - you need to add comprehensive tests!
 */
void demonstrateIterator() {
    cout << "\n=== Iterator Demonstration ===" << endl;

    // TODO: Create an iterator and demonstrate:
    // - operator++, operator--
    // - operator+=, operator-=
    // - setStart(), setEnd()
    // - isAtStart(), isAtEnd()
    // - Conversion operator
    // - Bounds checking

    cout << "Iterator demonstration not implemented - you must write this!" << endl;
}

/**
 * Basic example of testing Printer
 * This is INCOMPLETE - you need to add comprehensive tests!
 */
void demonstratePrinter() {
    cout << "\n=== Printer Demonstration ===" << endl;

    // TODO: Demonstrate Printer singleton:
    // - requestPrinter()
    // - returnPrinter()
    // - Reference counting
    // - TooManyPrintersDeleted exception
    // - PrinterNotInitialized exception

    cout << "Printer demonstration not implemented - you must write this!" << endl;
}

/**
 * ============================================================================
 * MAIN FUNCTION
 * ============================================================================
 *
 * This main is intentionally INCOMPLETE and BASIC.
 *
 * You MUST write your own comprehensive main.cpp that:
 * 1. Tests ALL functions of ALL classes
 * 2. Tests edge cases (empty, full, invalid inputs)
 * 3. Tests exception handling
 * 4. Tests memory management (use valgrind!)
 * 5. Verifies correct behavior with FitchFork's requirements
 *
 * Remember: FitchFork tests EVERYTHING. Your main should too!
 * ============================================================================
 */
int main() {
    cout << "============================================================================" << endl;
    cout << "SWIFT TUITION'S STUBBED MAIN - DEMONSTRATION ONLY" << endl;
    cout << "============================================================================" << endl;
    cout << "\n⚠️  WARNING: This is NOT a complete test suite!" << endl;
    cout << "⚠️  You MUST create your own comprehensive main.cpp" << endl;
    cout << "⚠️  DO NOT SUBMIT THIS MAIN TO FITCHFORK" << endl;
    cout << "\n============================================================================\n" << endl;

    // Run basic demonstrations
    demonstrateExceptions();
    demonstrateArray();
    demonstrateDLList();
    demonstrateQueue();
    demonstrateStack();
    demonstrateIterator();
    demonstratePrinter();

    cout << "\n============================================================================" << endl;
    cout << "END OF DEMONSTRATION" << endl;
    cout << "============================================================================" << endl;
    cout << "\nNext steps:" << endl;
    cout << "1. Implement the stubbed functions in each .cpp file" << endl;
    cout << "2. Write your own comprehensive main.cpp" << endl;
    cout << "3. Test with valgrind for memory leaks" << endl;
    cout << "4. Submit to FitchFork and aim for 410/410!" << endl;
    cout << "\n============================================================================\n" << endl;

    return 0;
}
