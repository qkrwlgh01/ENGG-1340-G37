#include <fstream>
#include "header.h"

vector<string> import_words(int num_letters)
{
    string word, filename;
    vector<string> words;
    ifstream fin;

    switch(num_letters) // import txt file storing words with corresponding length (name to be declard)
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
    
    return words;
}
