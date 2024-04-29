#include "import_words_header.h" //Include the header for function declaration
#include <fstream> //Include for file stream operations

// Function that imports words from a file into a vector of strings
std::vector<std::string> import_words() {
    std::vector<std::string> words; // Vector to store words
    std::ifstream file("words.txt"); // Input file stream used to read the file
    std::string word; // String to store each word read

    // Read words from the file until EOF
    while (file >> word) {
        words.push_back(word); // Add each word to the vector
    }

    file.close();
    return words;
}
