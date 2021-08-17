#include <SFML/Graphics.hpp>
#include "Game.h"
#include <iostream>
int main()
{
    sf::RenderWindow gameWindow(sf::VideoMode(800, 600), "SFML Roguelike");
    Game game(gameWindow);
    game.Run();

    return 0;
}