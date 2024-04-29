#ifndef FILE_READ_UTIL_H //These preprocessor directives form an include guard to prevent multiple inclusions of this header file.
#define FILE_READ_UTIL_H //FILE_READ_UTIL_H is defined for not using multiple time the same thing.

#include <string>

// Declaration of a function that reads the contents of a file into a string
std::string read_file_to_string(const std::string& filepath);

#endif
