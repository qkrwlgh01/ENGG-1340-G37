#include <algorithm>
#include <cstdlib>
#include <ctime>
#include "header.h"

// ramdomly select specified number of words with specified length for the single game
vector<string> select_words(const vector<string>& words, int word_length, int num_words)
{
    string word;
    int size = words.size();
    vector<string> wordles;

    srand(time(NULL));

    for (int i = 0; i < num_words; i++) {
        word = words[rand() % size];
        if (wordles.find(to_lower_case(word)) == -1) { // avoid repeated selection
            wordles.push_back(to_lower_case(word));
        }
    }

    return wordles;
}
