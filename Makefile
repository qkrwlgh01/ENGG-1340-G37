# Compiler and linker configurations
CXX = g++
CXXFLAGS = -Wall -g   # Compiler flags, -Wall for all warnings, -g for debugging information
LDFLAGS =  # Linker flags

# Source files and headers
SOURCES = main.cpp import_words.cpp print_char.cpp file_read_until.cpp select_words.cpp to_lower_case.cpp difference.cpp
HEADERS = import_words_header.h print_char_header.h file_read_until.h scoreboard.h
OBJECTS = $(SOURCES:.cpp=.o)   # Object files, derived from source files

# Executable name
EXECUTABLE = wordle

# Default target
all: $(EXECUTABLE)   # Default make target builds the executable

# Link the program
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(LDFLAGS) -o $@ $^

# Compile source files into objects
%.o: %.cpp $(HEADERS)   # Pattern rule for object file generation from source files
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)   # Clean rule to remove object files and executable

# Phony targets
.PHONY: all clean   # Declares 'all' and 'clean' as phony targets
