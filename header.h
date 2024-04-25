#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<string> import_words(int num_letters);
void correct_position(char correct_character);
void wrong_position(char correct_word);
void wrong_character(char wrong_character);
void diff(string guess, string wordle);


#endif
