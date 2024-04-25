#ifndef GAME_LEVELS_H
#define GAME_LEVELS_H

#include <vector>
#include <string>

struct GameLevel {
    int word_length;
    int num_words;
    int num_chances;
};

GameLevel setup_level(int level_choice);

#endif
