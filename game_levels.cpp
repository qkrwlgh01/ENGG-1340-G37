#include "game_levels.h"

// Setup different levels of the game
GameLevel setup_level(int level_choice) {
    GameLevel level;

    // Default values
    level.word_length = 5; // default word length
    level.num_chances = 6; // default number of chances

    switch (level_choice) {
        case 1:
            level.num_words = 5;
            break;
        case 2:
            level.num_words = 7;
            break;
        case 3:
            level.num_words = 9;
            break;
        default:
            // Default game level, could be the easiest or a balanced one
            level.num_words = 5;
            break;
    }

    return level;
}
