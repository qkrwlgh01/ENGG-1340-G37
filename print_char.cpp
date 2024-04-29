#include "print_char_header.h" // Including the header file for character display functions ensures separation and organization of declarations and definitions.
#include <cstdio> // Standard library for input and output functions.

// Displays a character that is correctly guessed and correctly placed
void correct_position(char correct_character) {
    printf("\033[32m[ %c ]\033[0m", correct_character);// Uses ANSI escape codes to 
}

// Displays a character that is correctly guessed but in the wrong position
void wrong_position(char wrong_character) {
    printf("\033[33m[ %c ]\033[0m", wrong_character);
}

// Displays a character that is not in the word at all
void wrong_character(char wrong_character) {
    printf("\033[0m[ %c ]\033[0m", wrong_character); // Resets the terminal color before displaying the character.

}
