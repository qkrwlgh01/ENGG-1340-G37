#include <cctype>
#include "header.h"

string toUpperCase(string word)
{
    for (int i = 0; i < word.length(); i++) {
        word[i] = toupper(word[i]);
    }
    return word;
}
