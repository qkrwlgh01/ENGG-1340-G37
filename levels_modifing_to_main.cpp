#include "import_words_header.h" // header for word input
#include "game_levels.h" // header for level setup

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Wordle Game");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Setup game level
        int level_choice;
        cout << "Choose a level (1: Easy, 2: Medium, 3: Hard): ";
        cin >> level_choice;
        GameLevel currentLevel = setup_level(level_choice);

        // Load words and select for the game based on the chosen level
        vector<string> words = import_words();
        vector<string> wordles = select_words(words, currentLevel.word_length, currentLevel.num_words);

        // Rest of the game logic
    }

    return 0;
}
