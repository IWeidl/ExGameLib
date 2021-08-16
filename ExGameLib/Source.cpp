#include <SFML/Graphics.hpp>
#include "Game.h"
#include <iostream>
int main()
{
    sf::RenderWindow gameWindow(sf::VideoMode(800, 600), "SFML Roguelike");
    gameWindow.setFramerateLimit(60);
    Game game(gameWindow);


    while (gameWindow.isOpen())
    {
        sf::Event event;
        while (gameWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                gameWindow.close();
        }
        gameWindow.clear();
        game.Draw();
        gameWindow.display();
    }

    return 0;
}