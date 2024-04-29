#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <string> // Includes the string library for using string data type
#include <vector> // Includes the vector library, an STL container used for dynamic data management

// Defines a structure to store player information
struct Player {
    std::string name;
    int score;
    int consecutiveWins;
};

// Function declaration to update the scoreboard
void updateScoreboard(const std::string& playerName, int score, int consecutiveWins);

// Function to display player rankings
void showRankings();

#endif // SCOREBOARD_H
