# COS 110 Assignment 3 - Stubs

Complete starter code for Assignment 3: Dynamic Data Structures

## Quick Start with GitHub Codespace

[![Open in GitHub Codespaces](https://github.com/codespaces/badge.svg)](https://codespaces.new/SwiftTuition/cos110-assignment3-stubs?quickstart=1)

Click the badge above to start coding in your browser immediately!

## 📋 What's Included

This repository contains:
- ✅ **14 header files** - Ready to use, all compile correctly
- ✅ **14 stub implementations** - Minimal structure for you to complete
- ✅ **Stubbed main.cpp** - Basic demonstration ONLY (see warning below)
- ✅ **Pre-configured Codespace** - Ready-to-use C++98 development environment

## ⚠️ CRITICAL WARNING: About main.cpp

> **The included main.cpp is "Swift Tuition's Stubbed Main" - a BASIC DEMONSTRATION ONLY!**

This is **NOT** the same main.cpp used in the actual FitchFork submission. It has already been uploaded to FitchFork during testing.

**❌ DO NOT SUBMIT THIS MAIN TO FITCHFORK ❌**

**✅ YOU MUST CREATE YOUR OWN main.cpp ✅**

Use the included main.cpp as a reference for:
- How to include headers
- Basic syntax examples
- Structure ideas

But write your own comprehensive test suite that tests:
- ALL functions of ALL classes
- Edge cases (empty, full, invalid inputs)
- Exception handling
- Memory management (valgrind!)
- FitchFork's specific requirements

## 🛠️ Compilation Modes

The Makefile provides two compilation modes to support different stages of development:

### Relaxed Mode (For Stubs)

**Use this while implementing stubs** - allows unused parameter warnings

```bash
make run-relaxed
```

**What it does:**
- Compiles with `-std=c++98 -Wall -Wno-unused-parameter`
- Suppresses warnings about unused parameters in stub functions
- Allows you to test basic compilation without implementing everything
- **Output:** Shows basic demonstration (like the example you saw)

**When to use:**
- ✅ While implementing stub functions one by one
- ✅ When testing basic functionality
- ✅ Early development stages

### Strict Mode (For Final Code)

**Use this before submission** - enforces FitchFork's strict requirements

```bash
make run-strict
```

**What it does:**
- Compiles with `-std=c++98 -Wall -Wextra -Werror`
- Treats ALL warnings as errors (FitchFork requirement)
- Forces you to use all parameters and fix all issues
- **Output:** Will fail to compile until all stubs are properly implemented

**When to use:**
- ✅ Before submitting to FitchFork
- ✅ After implementing all functions
- ✅ For final testing and validation

### Manual Compilation

If you prefer to compile manually:

```bash
# Relaxed mode (for stubs)
g++ -std=c++98 -Wall -Wno-unused-parameter main.cpp Exception.cpp InvalidIndexException.cpp InvalidSizeException.cpp ElementNotInListException.cpp OutOfBoundsException.cpp PrinterNotInitialized.cpp TooManyPrintersDeleted.cpp Printer.cpp -o main

# Strict mode (for final code)
g++ -std=c++98 -Wall -Wextra -Werror main.cpp Exception.cpp InvalidIndexException.cpp InvalidSizeException.cpp ElementNotInListException.cpp OutOfBoundsException.cpp PrinterNotInitialized.cpp TooManyPrintersDeleted.cpp Printer.cpp -o main
```

### Why Two Modes?

**Stubs have unused parameters by design:**
- The stubbed functions receive parameters they don't use yet
- Relaxed mode lets you test compilation without implementing everything
- Strict mode ensures your final code meets FitchFork's requirements

**FitchFork uses strict compilation:**
- Your final submission MUST compile with `-Werror`
- Always test in strict mode before submitting!

## 📦 Files Structure

```
.
├── Exception classes (7 files)
│   ├── Exception.h / Exception.cpp
│   ├── InvalidIndexException.h / InvalidIndexException.cpp
│   ├── InvalidSizeException.h / InvalidSizeException.cpp
│   ├── ElementNotInListException.h / ElementNotInListException.cpp
│   ├── OutOfBoundsException.h / OutOfBoundsException.cpp
│   ├── PrinterNotInitialized.h / PrinterNotInitialized.cpp
│   └── TooManyPrintersDeleted.h / TooManyPrintersDeleted.cpp
│
├── Data structure classes (7 files)
│   ├── List.h / List.cpp (base class)
│   ├── Array.h / Array.cpp (auto-resizing array)
│   ├── DLList.h / DLList.cpp (sorted doubly-linked list)
│   ├── Queue.h / Queue.cpp (FIFO queue)
│   ├── Stack.h / Stack.cpp (LIFO stack)
│   ├── Iterator.h / Iterator.cpp (template template iterator)
│   └── Printer.h / Printer.cpp (singleton printer)
│
└── main.cpp (test harness)
```

## 💻 Compilation

### In GitHub Codespace (Recommended)

The Codespace comes pre-configured. Just open the terminal and run:

```bash
g++ -std=c++98 -Wall main.cpp \
    Exception.cpp \
    InvalidIndexException.cpp \
    InvalidSizeException.cpp \
    ElementNotInListException.cpp \
    OutOfBoundsException.cpp \
    PrinterNotInitialized.cpp \
    TooManyPrintersDeleted.cpp \
    Printer.cpp \
    -o main

./main
```

### Locally (Linux/Mac)

```bash
g++ -std=c++98 -Wall main.cpp Exception.cpp InvalidIndexException.cpp \
    InvalidSizeException.cpp ElementNotInListException.cpp \
    OutOfBoundsException.cpp TooManyPrintersDeleted.cpp \
    PrinterNotInitialized.cpp Printer.cpp -o main
```

### With Valgrind (Memory Leak Detection)

```bash
# Compile with debug symbols
g++ -g -std=c++98 -Wall main.cpp [other files] -o main

# Run with valgrind
valgrind --leak-check=full --show-leak-kinds=all ./main
```

## ⚠️ Important Notes

### Template Files
**Do NOT compile template .cpp files directly!** They are included at the end of their .h files.

Only compile:
- main.cpp
- Exception classes (.cpp files)
- Printer.cpp (not a template)

### What You Need to Implement

#### Exception Classes (Simple)
- Implement `getMessage()` to return appropriate error messages
- Implement `operator<<` to output messages

#### Array Class (Medium)
- Auto-resize (double when full, halve when < half full)
- NULL element handling
- Bounds checking

#### DLList Class (Hard)
- **Swift Note:** Maintain sorted order (ascending)
- Circular doubly-linked structure
- Handle 6 insertion cases

#### Queue Class (Medium)
- FIFO behavior
- Enqueue at rear, dequeue from front

#### Stack Class (Medium)
- LIFO behavior
- Clone must preserve order (don't reverse!)

#### Iterator Class (Hard)
- operator-- must decrement FIRST, then check bounds
- Template template parameters

#### Printer Class (Medium)
- Singleton pattern
- Reference counting

## 🔑 Key Requirements

### DLList MUST Be Sorted
The list must maintain ascending sorted order at all times. This is tested by FitchFork!

### Iterator operator--
```cpp
// CORRECT (410/410):
Iterator& operator--() {
    currentPosition--;  // Decrement FIRST
    if (currentPosition < 0) {
        throw OutOfBoundsException();
    }
    return *this;
}

// WRONG (404/410):
Iterator& operator--() {
    if (currentPosition <= 0) {  // Check BEFORE decrement - WRONG!
        throw OutOfBoundsException();
    }
    currentPosition--;
    return *this;
}
```

### Stack Clone Order
Stack clone must preserve the original order, not reverse it!

## ✅ Pre-Submission Checklist

Before submitting to FitchFork:

- [ ] Compiles with `-std=c++98 -Wall` with no errors or warnings
- [ ] Valgrind reports "All heap blocks were freed"
- [ ] DLList maintains sorted order
- [ ] Array auto-resizes correctly
- [ ] Stack clone preserves order
- [ ] Iterator operator-- decrements first
- [ ] All edge cases tested (empty, single element, large datasets)

## 🎯 Target

**410/410** on FitchFork with zero memory leaks!

## 📝 License

These stubs are provided for educational purposes for COS 110 students.
