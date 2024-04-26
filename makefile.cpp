CXX = g++
CXXFLAGS = -Wall -std=c++11 -g

HEADER_FILES = print_char_header.h import_words_header.h
SOURCE_FILES = main.cpp to_lower_case.cpp select_words.cpp print_char.cpp import_words.cpp difference.cpp Graphic.cpp
OBJECT_FILES = $(SOURCE_FILES:.cpp=.o)
EXECUTABLE = game

DATA_FILES = word.txt winning.txt title.txt losing.txt Easter_egg.txt

BUILD_DIR = ./build

all: $(EXECUTABLE) copy_data

$(EXECUTABLE): $(OBJECT_FILES)
	$(CXX) $(CXXFLAGS) -o $(BUILD_DIR)/$@ $^

%.o: %.cpp $(HEADER_FILES)
	$(CXX) $(CXXFLAGS) -c $< -o $@

copy_data:
	@mkdir -p $(BUILD_DIR)/data
	@cp $(DATA_FILES) $(BUILD_DIR)/data/

clean:
	rm -f $(OBJECT_FILES) $(BUILD_DIR)/$(EXECUTABLE)
	rm -rf $(BUILD_DIR)/data

.PHONY: all clean copy_data
