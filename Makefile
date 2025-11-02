# COS 110 Assignment 3 Makefile
# Compiler and flags
CXX = g++
CXXFLAGS_STRICT = -std=c++98 -Wall -Wextra -Werror
CXXFLAGS_RELAXED = -std=c++98 -Wall -Wno-unused-parameter
CXXFLAGS = $(CXXFLAGS_STRICT)
DEBUG_FLAGS = -g
VALGRIND = valgrind
VALGRIND_FLAGS = --leak-check=full --show-leak-kinds=all --track-origins=yes

# Target executable
TARGET = main

# Source files (only non-template .cpp files)
SOURCES = main.cpp \
          Exception.cpp \
          InvalidIndexException.cpp \
          InvalidSizeException.cpp \
          ElementNotInListException.cpp \
          OutOfBoundsException.cpp \
          PrinterNotInitialized.cpp \
          TooManyPrintersDeleted.cpp \
          Printer.cpp

# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# Default target
all: $(TARGET)

# Build target
$(TARGET): $(OBJECTS)
	@echo "Linking $(TARGET)..."
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)
	@echo "Build complete: $(TARGET)"

# Compile source files to object files
%.o: %.cpp
	@echo "Compiling $<..."
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Build with debug symbols (for valgrind)
debug: CXXFLAGS += $(DEBUG_FLAGS)
debug: clean $(TARGET)
	@echo "Debug build complete"

# Run the program
run: $(TARGET)
	@echo "Running $(TARGET)..."
	./$(TARGET)

# Check for memory leaks with valgrind
memcheck: debug
	@echo "Checking for memory leaks with valgrind..."
	$(VALGRIND) $(VALGRIND_FLAGS) ./$(TARGET)

# Quick valgrind check (less verbose)
leak: debug
	@echo "Quick memory leak check..."
	$(VALGRIND) --leak-check=full ./$(TARGET)

# Compile and run in one step
test: $(TARGET) run

# NON-STRICT MODE: Compile with relaxed warnings (allows unused parameters)
# Use this while working with stubs that aren't fully implemented yet
relaxed: CXXFLAGS = $(CXXFLAGS_RELAXED)
relaxed: clean $(TARGET)
	@echo "Relaxed build complete (unused parameter warnings suppressed)"

# Run in relaxed mode (for stubs)
run-relaxed: relaxed
	@echo "Running $(TARGET) (relaxed mode)..."
	./$(TARGET)

# STRICT MODE: Compile with all warnings as errors (FitchFork requirement)
# Use this before final submission to ensure your code meets FitchFork standards
strict: CXXFLAGS = $(CXXFLAGS_STRICT)
strict: clean $(TARGET)
	@echo "Strict build complete (all warnings are errors)"

# Run in strict mode (for final testing)
run-strict: strict
	@echo "Running $(TARGET) (strict mode)..."
	./$(TARGET)

# Clean build artifacts
clean:
	@echo "Cleaning build artifacts..."
	rm -f $(OBJECTS) $(TARGET)
	@echo "Clean complete"

# Remove all generated files
distclean: clean
	@echo "Removing all generated files..."
	rm -f *~ *.swp *.bak
	@echo "Distclean complete"

# Rebuild everything
rebuild: clean all

# Show help
help:
	@echo "=========================================================================="
	@echo "COS 110 Assignment 3 - Makefile Commands"
	@echo "=========================================================================="
	@echo ""
	@echo "COMPILATION MODES:"
	@echo "  make relaxed     - Compile with relaxed warnings (for stubs)"
	@echo "  make run-relaxed - Compile and run in relaxed mode"
	@echo "  make strict      - Compile with strict warnings (for final code)"
	@echo "  make run-strict  - Compile and run in strict mode"
	@echo ""
	@echo "STANDARD TARGETS:"
	@echo "  make             - Build the project (strict mode)"
	@echo "  make all         - Build the project (strict mode)"
	@echo "  make run         - Build and run (strict mode)"
	@echo "  make debug       - Build with debug symbols"
	@echo "  make test        - Build and run"
	@echo ""
	@echo "MEMORY CHECKING:"
	@echo "  make memcheck    - Check for memory leaks with valgrind (verbose)"
	@echo "  make leak        - Quick memory leak check"
	@echo ""
	@echo "CLEANUP:"
	@echo "  make clean       - Remove object files and executable"
	@echo "  make distclean   - Remove all generated files"
	@echo "  make rebuild     - Clean and rebuild everything"
	@echo ""
	@echo "=========================================================================="
	@echo "RECOMMENDED WORKFLOW:"
	@echo "=========================================================================="
	@echo "1. While implementing stubs:"
	@echo "   make run-relaxed      (allows unused parameter warnings)"
	@echo ""
	@echo "2. Before FitchFork submission:"
	@echo "   make run-strict       (enforces FitchFork's strict requirements)"
	@echo "   make memcheck         (check for memory leaks)"
	@echo ""
	@echo "=========================================================================="
	@echo ""
	@echo "For more details, see README.md or GETTING_STARTED.md"
	@echo ""

# Phony targets (not real files)
.PHONY: all debug run memcheck leak test clean distclean rebuild help relaxed run-relaxed strict run-strict
