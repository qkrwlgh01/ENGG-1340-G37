#include <fstream>
#include <cstdlib>
#include <ctime>
#include "header.h"

vector<string> import_words(int word_length)
{
    string word, filename;
    vector<string> words;
    ifstream fin;

    switch(word_length) // import txt file storing words with corresponding length (name to be declard)
    {
        case 5: filename = ""
        case 7: filename = ""
        case 9: filename = ""
        default: filename = ""
    }

    fin.open(c_str(filename));
    
    while(fin >> word) { // extract the whole file
        words.push_back(word);
    }
    fin.close();

    srand(time(NULL));
    for (int i = 0; i < 
    return words;
}
