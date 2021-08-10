#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "GameData.h"
#include "Entity.h"
#include "Player.h"


class Game
{
public:
	Game(sf::RenderWindow& wnd);
	void Draw();


protected:
	GameData gameData;

private:
	sf::RenderWindow& gameWindow;
};

