#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;
void diff(string guess, string wordle);
void correct_position(char correct_character);
void wrong_position(char correct_word);
void wrong_character(char wrong_character);

#endif
