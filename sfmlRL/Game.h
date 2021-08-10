#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Entity.h"
#include "Player.h"
class Game
{
public:
	Game(sf::RenderWindow& wnd);
	void Draw();
	
protected:
	std::vector<Entity> entities;

private:
	sf::RenderWindow& gameWindow;
};

