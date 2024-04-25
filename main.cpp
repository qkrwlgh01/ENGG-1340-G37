#include <iostream>
#include <cstdlib>
#include <ctime>
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
        string guess, wordle, filename; // wordle = word to be guessed
        int word_length, num_words, num_tries;

        // Initialize game conditions
        printf("Please select word length (5/7/9): ");
        scanf("%d", &word_length);
        printf("Please select number of words to challenge: ");
        scanf("%d", &num_words)
        
        // Import  wordle (words to be guessed)
        vector<string> wordles;
        wordles = import_words(word_length);
        
        
        // Guessing loop
        for (int i = 0; i < num_tries; i++) 
        {
            printf("Your guess (%d-letter word)", word_length);
            cin >> guess;
            
            if (guess.length() != word_length) {
                i--;
                cout << "Invalid word length!" << endl;
                continue;
            }else{
                diff(guess, wordle);
                printf("(%d/%d)\n", i + 1, num_tries);
            }

            if (guess == wordle) {
                cout << "Correct!" << endl;
                break;
            }else{
                cout << "Try again!" << endl;
            }
        }
        window.clear(); // Clear the window
        
        // Draw objects to the window
        
        window.display(); // Display the window
    }
    
    return 0;
}
