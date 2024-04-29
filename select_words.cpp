#include "import_words_header.h" // Including the header file for word import functionality.
#include <cstdlib> // For random number generation
#include <ctime>  // Includes library for handling time (used here for random seeding).
#include <algorithm> // Includes standard library for algorithms, used for std::find.

// Function to select a specified number of words of a certain length from a list of words.
std::vector<std::string> select_words(const std::vector<std::string>& words, int word_length, int num_words) {
    std::vector<std::string> selected_words; // Vector to store selected words.
    srand(time(NULL)); // Seed the random number generator with the current time.

    while (selected_words.size() < num_words) {
        std::string candidate = words[rand() % words.size()]; // Randomly select a word.
        if (candidate.length() == word_length && std::find(selected_words.begin(), selected_words.end(), candidate) == selected_words.end()) {
            selected_words.push_back(candidate); // Add to the list of selected words.
        }
    }

    return selected_words;
}
