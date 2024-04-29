#include <iostream> // Standard library for input and output operations
#include <string> //Include the string library for using string data type

//Function to compare two strings and output the result based on character matches
void diff(const std::string& guess, const std::string& wordle) {
    for (size_t i = 0; i < guess.size(); i++) {
        if (guess[i] == wordle[i]) {
            std::cout << guess[i];  // Output the character itself for an exact match
        } else {
            bool found = false;
            for (size_t j = 0; j < wordle.size(); j++) {
                if (guess[i] == wordle[j]) {
                    std::cout << '+';  // Output '+' for a character that is correct 
                    found = true;
                    break;
                }
            }
            if (!found) {
                std::cout << '_'; // Output '_' for a character that does not match 
            }
        }
    }
    std::cout << std::endl;
}
