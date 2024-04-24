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
        
        window.clear(); // Clear the window
        
        // Draw objects to the window
        
        window.display(); // Display the window
    }
    
    return 0;
}
