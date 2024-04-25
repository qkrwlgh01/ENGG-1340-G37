#include <fstream>
#include "header.h"

// import all words in word.txt for selection afterwards
vector<string> import_words()
{
    string word;
    vector<string> words;
    ifstream fin("word.txt");
    
    while(fin >> word) {
        words.push_back(word);
    }
    fin.close();

    return words;
}
