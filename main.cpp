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
        int word_length, num_words, num_tries;

        // Initialize game conditions
        printf("Word length? ");
        scanf("%d", &word_length);
        printf("Number of words to challenge? ");
        scanf("%d", &num_words);
        printf("Number of tries for each word? ");
        scanf("%d", &num_tries);
        
        // Load word.txt and select words for the game
        vector<string> words; // storing all words in word.txt
        vector<string> wordles; // storing words to be guessed
        words = import_words();
        wordles = select_words(&words, word_length, num_words);
        
        // Guessing loop
        string guess;
        for (int j = 0; j < num_words; j++) 
        {
            for (int i = 0; i < num_tries; i++) 
            {
                printf("Your guess: ");
                cin >> guess;
            
                if (guess.length() != word_length) {
                    i--;
                    cout << "Invalid word length!" << endl;
                    continue;
                }else{
                    diff(guess, wordles[j]);
                    printf("(%d/%d)\n", i + 1, num_tries);
                }

                if (guess == wordle) { // showing winning / losing statements (to be changed)
                    cout << "Correct!" << endl;
                    break;
                }else{
                    cout << "Try again!" << endl;
                }
            }
        }
        window.clear(); // Clear the window
        
        // Draw objects to the window
        
        window.display(); // Display the window
    }
    
    return 0;
}
