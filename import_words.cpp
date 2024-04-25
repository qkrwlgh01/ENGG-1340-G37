#include <fstream>
#include <cstdlib>
#include <ctime>
#include "header.h"

vector<string> import_words(int word_length)
{
    string word, filename;
    vector<string> words;
    ifstream fin("word.txt");
    
    while(fin >> word) {
        if (word.length() == word_length)
            words.push_back(word);
    }
    fin.close();

    srand(time(NULL));
    for (int i = 0; i < 
    return words;
}
