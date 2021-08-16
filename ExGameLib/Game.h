#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "GameData.h"
#include "EntityManager.h"
#include "Player.h"
#include "TextureManager.h"

class Game
{
public:
	Game(sf::RenderWindow& wnd);
	void Draw();
	GameData gameData;

private:
	sf::RenderWindow& gameWindow;
};

