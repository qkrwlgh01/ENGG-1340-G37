#include <iostream>
#include <fstream>
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
        int num_wordle, num_tries;
        
        // Import of wordle (words to be guessed)
        ifstream fin;
        fin.open(filename);

        vector<string> wordles;
        
        // Guessing loop
        for (int i = 0; i < num_tries; i++) {
            printf("Make your guess (%d-letter word)", wordle.length());
            cin >> guess;
            if (guess.length() != wordle.length()) {
                i--;
                cout << "Invalid word length." << endl;
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
        
        window.clear(); // Clear the window
        
        // Draw objects to the window
        
        window.display(); // Display the window
    }
    
    return 0;
}
