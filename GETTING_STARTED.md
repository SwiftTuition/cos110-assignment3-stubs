# Getting Started - COS 110 Assignment 3

Welcome! This guide will help you get started with Assignment 3: Dynamic Data Structures.

## 📚 Assignment Specifications

Before you start coding, **read the assignment specifications**:
- **[assignment_specs.md](assignment_specs.md)** - Complete assignment requirements and UML diagrams
- **[figure_descriptions.md](figure_descriptions.md)** - Detailed descriptions of all UML figures

## ⚠️ CRITICAL WARNING: About main.cpp

> **The included main.cpp is "Swift Tuition's Stubbed Main" - a BASIC DEMONSTRATION ONLY!**

**This is NOT the same main.cpp used in the actual FitchFork submission.**

**❌ DO NOT SUBMIT THIS MAIN TO FITCHFORK ❌**

The stubbed main.cpp has already been uploaded to FitchFork during testing. Submitting it may be flagged as a duplicate.

**✅ YOU MUST CREATE YOUR OWN COMPREHENSIVE main.cpp ✅**

The included main demonstrates:
- Basic syntax and usage patterns
- How to include headers correctly
- Simple examples of each class

**You must write your own test suite that thoroughly tests ALL functionality!**

## Quick Start Options

### Option 1: GitHub Codespace (Recommended)
Click the badge in [README.md](README.md) to launch a pre-configured development environment in your browser. No installation needed!

### Option 2: Local Development
Clone this repository and compile locally using the provided Makefile.

## 🛠️ Compilation Modes

**IMPORTANT:** The Makefile supports two compilation modes for different development stages.

### Relaxed Mode (While Implementing)

Use this while working with stubs:

```bash
make run-relaxed
```

**What happens:**
- ✅ Compiles successfully even with unimplemented stub functions
- ✅ Suppresses "unused parameter" warnings
- ✅ Shows basic demonstration output
- ✅ Perfect for testing as you implement functions one by one

**Example output:**
```
============================================================================
SWIFT TUITION'S STUBBED MAIN - DEMONSTRATION ONLY
============================================================================
⚠️  WARNING: This is NOT a complete test suite!
⚠️  You MUST create your own comprehensive main.cpp
============================================================================

=== Exception Demonstration ===
InvalidIndexException message:

=== Array Demonstration ===
Created array with capacity: 0
After adding elements:
...
```

### Strict Mode (Before Submission)

Use this before submitting to FitchFork:

```bash
make run-strict
```

**What happens:**
- ❌ Will fail to compile if ANY stub is unimplemented
- ❌ Treats all warnings as errors (FitchFork requirement)
- ✅ Forces you to properly implement ALL functions
- ✅ Ensures code meets FitchFork's standards

**This is what FitchFork uses!** Always test in strict mode before submitting.

### Quick Reference

| Stage | Command | Purpose |
|-------|---------|---------|
| **During development** | `make run-relaxed` | Test stubs as you implement |
| **Before submission** | `make run-strict` | Verify FitchFork compliance |
| **Memory leak check** | `make memcheck` | Find memory issues |

## 🛠️ Using the Makefile

### All Available Commands

| Command | Description |
|---------|-------------|
| `make run-relaxed` | **Compile and run with relaxed warnings** (for stubs) |
| `make run-strict` | **Compile and run with strict warnings** (for final code) |
| `make` or `make all` | Build the project (strict mode) |
| `make debug` | Build with debug symbols (for valgrind) |
| `make run` | Build and run the program (strict mode) |
| `make test` | Same as `make run` |
| `make memcheck` | Full valgrind memory leak check (verbose) |
| `make leak` | Quick valgrind leak check |
| `make clean` | Remove object files and executable |
| `make distclean` | Remove all generated files |
| `make rebuild` | Clean and rebuild everything |
| `make help` | Show help message |

### Example Workflow

```bash
# 1. Start fresh
make clean

# 2. Build and run to test your code
make run

# 3. Check for memory leaks before submission
make memcheck

# Expected output (no leaks):
# All heap blocks were freed -- no leaks are possible
# ERROR SUMMARY: 0 errors
```

## 📁 File Structure

```
.
├── GETTING_STARTED.md        ← You are here
├── README.md                 ← Project overview and Codespace setup
├── Makefile                  ← Build automation
├── assignment_specs.md       ← Assignment requirements (READ THIS!)
├── figure_descriptions.md    ← UML diagram descriptions
│
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
│   ├── List.h / List.cpp
│   ├── Array.h / Array.cpp
│   ├── DLList.h / DLList.cpp
│   ├── Queue.h / Queue.cpp
│   ├── Stack.h / Stack.cpp
│   ├── Iterator.h / Iterator.cpp
│   └── Printer.h / Printer.cpp
│
├── main.cpp                  ← Your test file
└── .devcontainer/            ← Codespace configuration
    └── devcontainer.json
```

## 🎯 Implementation Order (Recommended)

Follow this order to build on previous work:

1. **Exception Hierarchy**
   - Simple, foundational
   - Test immediately
   - Needed by everything else

2. **Array**
   - Practice templates
   - Auto-resize logic
   - No dependencies

3. **DLList**
   - Master sorted insertion
   - Doubly-linked structure
   - Most complex data structure

4. **Queue & Stack**
   - Similar patterns
   - Build confidence
   - Queue is FIFO, Stack is LIFO

5. **Iterator**
   - Template template parameters
   - Key operator-- fix
   - Uses your data structures

6. **Printer**
   - Singleton pattern
   - Uses Iterator internally

## ⚠️ Key Requirements

### 1. DLList Must Maintain Sorted Order
```cpp
DLList<int> list;
list += 30;  // [30]
list += 10;  // [10, 30] - inserted BEFORE 30!
list += 20;  // [10, 20, 30] - inserted BETWEEN!
```

### 2. Iterator operator-- Order Matters
```cpp
// CORRECT (410/410):
Iterator& operator--() {
    currentPosition--;  // Decrement FIRST
    if (currentPosition < 0) {
        throw OutOfBoundsException();
    }
    return *this;
}
```

### 3. Stack Clone Preserves Order
Don't reverse the stack when cloning!

### 4. Const Correctness
The UML doesn't show const qualifiers, but you MUST add them to functions that don't modify the object.

## 🧪 Testing Your Code

### Quick Test
```bash
make run
```

### Memory Leak Check (IMPORTANT!)
```bash
make memcheck
```

Expected output:
```
All heap blocks were freed -- no leaks are possible
ERROR SUMMARY: 0 errors from 0 contexts
```

### What to Test
- ✅ Empty containers
- ✅ Single element
- ✅ Multiple elements
- ✅ Edge cases (resize boundaries, duplicates, etc.)
- ✅ Exception throwing
- ✅ Memory leaks (valgrind)

## 📝 Pre-Submission Checklist

Before submitting to FitchFork:

- [ ] Compiles with `make` with no errors or warnings
- [ ] `make memcheck` shows no memory leaks
- [ ] DLList maintains sorted order (test explicitly!)
- [ ] Array auto-resizes correctly (up and down)
- [ ] Stack clone preserves order (not reversed)
- [ ] Iterator operator-- decrements first, checks after
- [ ] Printer singleton works (only one instance)
- [ ] All edge cases tested
- [ ] Removed all debug print statements

## 💡 Tips for Success

### Read the Specs First
Before writing ANY code:
1. Read [assignment_specs.md](assignment_specs.md) completely
2. Study [figure_descriptions.md](figure_descriptions.md) for UML details
3. Understand what each class does

### Implement Incrementally
1. Implement one function at a time
2. Test after each function
3. Use `make run` frequently
4. Check for memory leaks often with `make memcheck`

### Don't Compile Template .cpp Files!
The Makefile handles this correctly. Templates are included in .h files.

### Use Valgrind Early and Often
Don't wait until the end to check for memory leaks. Check after implementing each class.

### Test Edge Cases
Empty containers, single elements, boundary conditions - these often reveal bugs.

## 🆘 Need Help?

### Compilation Issues
```bash
# Clean and rebuild
make clean
make

# Check for specific errors in output
```

### Memory Leaks
```bash
# Run full valgrind check
make memcheck

# Look for "definitely lost" or "possibly lost"
# Each leak shows file:line number
```

### Segmentation Faults
Common causes:
- Dereferencing NULL pointers
- Accessing deleted memory
- Array index out of bounds
- Circular list broken (DLList)

Use valgrind to find the exact line:
```bash
make memcheck
```

## 🎓 Learning Resources

This repository provides the stubs. For comprehensive learning materials:
- Theory explanations
- Implementation patterns
- Testing strategies
- Common pitfalls

See the full study guide (if provided by your tutor).

## 📞 Questions?

1. Re-read the assignment specs
2. Check the UML diagrams
3. Test your code thoroughly
4. Use valgrind to debug memory issues
5. Ask your tutor if still stuck

## 🎯 Target

**410/410** on FitchFork with **zero memory leaks**!

Good luck!
