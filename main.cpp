#include<iostream>
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
        string guess, wordle;
        int guessing_time;
        
        // import of wordle (word to be guessed) (missing)
        
        // guessing 
        for (int i = 0; i < guessing_time; i++) {
            cout << "Make your guess " << "\(number of letters = " << itos(wordle.length()) << "\): ";
            cin >> guess;
            if (guess.length() != wordle.length()) {
                i--;
                cout << "Invalid word length." << endl;
                continue;
            }else{
                diff(guess, wordle);
            }

            if (guess == wordle) {
                cout << "
        
        window.clear(); // Clear the window
        
        // Draw objects to the window
        
        window.display(); // Display the window
    }
    
    return 0;
}
