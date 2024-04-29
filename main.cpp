#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // To use sorting and other algorithms like std::find_if.
#include <limits> // For std::numeric_limits.
#include <fstream> // For file input/output operations.

// External headers for different type of functions.
#include "import_words_header.h" 
#include "print_char_header.h" 
#include "file_read_until.h" 
#include "scoreboard.h" 

// ANSI color codes for enhancing terminal output.
#define ANSI_COLOR_RED      "\x1b[31m"
#define ANSI_COLOR_GREEN    "\x1b[32m"
#define ANSI_COLOR_BRIGHT_BLUE     "\x1b[94m"
#define ANSI_COLOR_BRIGHT_MAGENTA  "\x1b[95m"
#define ANSI_COLOR_RESET "\x1b[0m"

// Function to read file content into a string and apply color formatting.
std::string read_file_to_string(const std::string& filename, const std::string& color) {
    std::ifstream file(filename);
    std::string content, line;
    if (file.is_open()) {
        while (getline(file, line)) {
            content += line + "\n";
        }
        file.close();
    }
    return color + content + ANSI_COLOR_RESET;
}

std::vector<std::string> import_words(); // Declaration for importing word list.
extern std::vector<std::string> select_words(const std::vector<std::string>& words, int word_length, int num_words);
extern std::string to_lower_case(std::string word);
extern void diff(const std::string& guess, const std::string& wordle);
extern std::string read_file_to_string(const std::string& filename);

std::vector<Player> scoreboard; // Vector used as a data structure to store player scores.

// Function to update the player's score and consecutive wins in the scoreboard.
void updateScoreboard(const std::string& playerName, int score, int consecutiveWins) {
    auto it = std::find_if(scoreboard.begin(), scoreboard.end(), [&](const Player& player) {
        return player.name == playerName;
    });

    if (it != scoreboard.end()) {
        
        it->score = std::max(it->score, score);
        it->consecutiveWins = std::max(it->consecutiveWins, consecutiveWins);
    } else {
        
        scoreboard.push_back({playerName, score, consecutiveWins});
    }
}
// Function to display the game menu.
void showMenu() {
    std::cout << "\n1. Game Start\n";
    std::cout << "2. Rankings\n";
    std::cout << "3. Game Instructions\n";
    std::cout << "4. Quit Game\n";
    std::cout << "Enter your choice: ";
}
// Function to get the user's menu choice.
int getChoice() {
    int choice;
    while (!(std::cin >> choice)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter an integer: ";
    }
    return choice;
}
// Function to display game instructions.
void showInstructions() {
    std::cout << "\n\nGame Instructions\n\n";
    std::cout << "Players have six attempts to guess a five-letter word.\n\n";
    std::cout << "Feedback will be given for each guess.\n\n";
    std::cout << "If the player types a correct letter but in a different spot a \"+\" sign will appear, meaning \"the letter exists but in a different place\".\n\n";
    std::cout << "If the player types a correct letter in the correct spot the letter will \"remain\" at the spot.\n\n";
    std::cout << "Every time you get the word correct you earn 10 point and you earn a consequtive win points for your streaks will lead to special gift!.\n\n";
    std::cout << "However, if you lose the next game your points will remain but your consequtive win points will be ZERO again.\n\n";
    std::cout << "So becareful and try to win the game in a row for your suprise gift!. GOOD LUCK!!\n\n";
}
// Function to display player rankings.
void showRankings() {
    std::sort(scoreboard.begin(), scoreboard.end(), [](const Player& a, const Player& b) {
        return a.score > b.score;
    });
    std::cout << "\nRankings:\n";
    for (const auto& player : scoreboard) {
        std::cout << "Player: " << player.name << ", Score: " << player.score << ", Consecutive Wins: " << player.consecutiveWins << std::endl;
    }
}
// Main function to handle the Wordle game logic.
void playWordleGame() {
    std::string playerName;
    std::cout << "Enter your name: ";
    std::cin >> playerName;
    int score = 0;  
    int consecutiveWins = 0; 
    std::vector<std::string> words = import_words();
    int word_length = 5, num_words = 200, num_chances = 6;
    std::vector<std::string> wordles = select_words(words, word_length, num_words);

    for (int j = 0; j < num_words; j++) {
        std::string wordle = wordles[j];
        std::cout << "\nGuess the word: " << std::string(word_length, '*') << " (word length " << word_length << ")\n" << "Press 0 to Exit.\n";
        bool guessed = false;
        for (int i = 0; i < num_chances; i++) {
            std::string guess;
            std::cout << "Enter your guess: ";
            std::cin >> guess;
            if (guess == "0") {
                std::cout << "Exiting to main menu.\n";
                updateScoreboard(playerName, score, consecutiveWins);
                return;
            }
            guess = to_lower_case(guess);
            if (guess.length() != word_length) {
                std::cout << "Please enter a word of exactly " << word_length << " letters.\n";
                i--;
                continue;
            }
            diff(guess, wordle);
            if (guess == wordle) {
                std::cout << read_file_to_string("winning.txt", ANSI_COLOR_GREEN) << std::endl;
                guessed = true;
                score += 10;  
                consecutiveWins++;
                break;
            }
        }
        if (!guessed) {
            consecutiveWins = 0;  
            std::cout << read_file_to_string("losing.txt", ANSI_COLOR_RED) << std::endl;
            std::cout << "The correct word was: " << wordle << std::endl;
        }
        if (consecutiveWins % 5 == 0 && consecutiveWins != 0) {
            std::cout << read_file_to_string("Easter_egg.txt", ANSI_COLOR_BRIGHT_MAGENTA) << std::endl;
        }
    }
    updateScoreboard(playerName, score, consecutiveWins);
}
// Main function of the program, orchestrating the game.
int main() {
    std::cout << read_file_to_string("title.txt",ANSI_COLOR_BRIGHT_BLUE) << std::endl;
    int choice;
    do {
        showMenu();
        choice = getChoice();
        switch (choice) {
            case 1:
                playWordleGame();
                break;
            case 2:
                showRankings();
                break;
            case 3:
                showInstructions();
                break;
            case 4:
                std::cout << "Quitting game. Thank you for playing!\n";
                break;
            default:
                std::cout << "Invalid option. Please try again.\n";
                break;
        }
    } while (choice != 4);
    return 0;
}
