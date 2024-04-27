#include <SFML/Graphics.hpp>
#include "header.h" //header file

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Window Title");
    
    // Main game loop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        // Update the game logic
        //int word_length, num_words, num_chances;

        // Initialize game conditions\
        //printf("Choose difficulty(1-easy, 2-medium, 3-hard, just type the number): ");
        //scanf("%d", &difficulty);
        printf("Word length? ");
        scanf("%d", &word_length);
        printf("Number of words to challenge? ");
        scanf("%d", &num_words);
        printf("Number of chances for each word? ");
        scanf("%d", &num_chances);
        
        // Load word.txt and select words for the game
        vector<string> words; // storing all words in word.txt
        vector<string> wordles; // storing words to be guessed
        words = import_words();
        wordles = select_words(&words, word_length, num_words);
        
        // Guess loop
        for (int j = 0; j < num_words; j++) 
        {
            string guess, wordle;
            wordle = wordles[j]; // correct word of the round
            printf("Word %d:", j + 1);
            for (int i = 0; i < num_chances; i++) // keep trying until correct guess or chance used up
            {
                printf("Your guess (%d/%d): ", i + 1, num_chances);
                cin >> guess; // user guess
            
                if (guess.length() != word_length) {
                    i--;
                    cout << "Invalid word length!" << endl;
                    continue;
                }else{
                    diff(guess, wordle);
                    if (guess == wordle) {
                        cout << "Bingo!" << endl;
                        break;
                    }else{
                        cout << "Try again!" << endl;
                    }
                }
            }
            
            if (i == num_chances) { // game over (to be modified)
                break;
            }
        }
        if (j == num_words) {
            // win (to be modified)
        }
        
        window.clear(); // Clear the window
        
        // Draw objects to the window
        
        window.display(); // Display the window
    }
    
    return 0;
}
