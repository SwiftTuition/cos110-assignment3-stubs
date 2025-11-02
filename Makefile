# COS 110 Assignment 3 Makefile
# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror
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
	@echo "COS 110 Assignment 3 - Makefile Commands"
	@echo ""
	@echo "Available targets:"
	@echo "  make          - Build the project (default)"
	@echo "  make all      - Build the project"
	@echo "  make debug    - Build with debug symbols"
	@echo "  make run      - Build and run the program"
	@echo "  make test     - Build and run (same as 'make run')"
	@echo "  make memcheck - Check for memory leaks with valgrind (verbose)"
	@echo "  make leak     - Quick memory leak check"
	@echo "  make clean    - Remove object files and executable"
	@echo "  make distclean- Remove all generated files"
	@echo "  make rebuild  - Clean and rebuild everything"
	@echo "  make help     - Show this help message"
	@echo ""
	@echo "Examples:"
	@echo "  make run      - Compile and run your program"
	@echo "  make memcheck - Check for memory leaks"
	@echo "  make clean    - Clean up before submission"

# Phony targets (not real files)
.PHONY: all debug run memcheck leak test clean distclean rebuild help
