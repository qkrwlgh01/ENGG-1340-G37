# Compiler settings - Can be customized.
CXX = g++
CXXFLAGS = -Wall -std=c++11 -g

# Files
HEADER_FILES = print_char_header.h import_words_header.h
SOURCE_FILES = main.cpp to_lower_case.cpp select_words.cpp print_char.cpp import_words.cpp difference.cpp Graphic.cpp
OBJECT_FILES = $(SOURCE_FILES:.cpp=.o)
EXECUTABLE = game

# Data files
DATA_FILES = word.txt winning.txt title.txt losing.txt easter_egg.txt

# Build directory
BUILD_DIR = ./build

# Build
all: $(EXECUTABLE) copy_data

$(EXECUTABLE): $(OBJECT_FILES)
	$(CXX) $(CXXFLAGS) -o $(BUILD_DIR)/$@ $^

# Compile step
%.o: %.cpp $(HEADER_FILES)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Copy data files
copy_data:
	@mkdir -p $(BUILD_DIR)/data
	@cp $(DATA_FILES) $(BUILD_DIR)/data/

# Clean
clean:
	rm -f $(OBJECT_FILES) $(BUILD_DIR)/$(EXECUTABLE)
	rm -rf $(BUILD_DIR)/data

# Phony targets
.PHONY: all clean copy_data
