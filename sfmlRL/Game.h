#pragma once
#include <SFML/Graphics.hpp>
class Game
{
public:
	Game(sf::RenderWindow& wnd);
	void Draw();	

private:
	sf::RenderWindow& wnd;
};

