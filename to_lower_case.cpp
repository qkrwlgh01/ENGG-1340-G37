#include <cctype>
#include "header.h"

string to_lower_case(string word)
{
    for (int i = 0; i < word.length(); i++) {
        word[i] = tolower(word[i]);
    }
    
    return word;
}
