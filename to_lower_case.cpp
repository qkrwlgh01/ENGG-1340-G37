#include <string>
#include <cctype> // Includes character handling functions such as std::tolower.

std::string to_lower_case(std::string word) {
    for (char& c : word) { // Range-based for loop to iterate over each character by reference.
        c = std::tolower(c); // Converts each character to lowercase.
    }
    return word;
}
