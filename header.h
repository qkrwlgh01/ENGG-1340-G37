#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;
string to_lower_case(string);
vector<string> import_words();
vector<string> select_words(vector<string>&, int, int);
void correct_position(char);
void wrong_position(char);
void wrong_character(char);
void diff(string, string);

#endif
