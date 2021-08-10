#include "Game.h"
Game::Game(sf::RenderWindow& gameWindow)
	: gameWindow(gameWindow)
{
}
void Game::Draw()
{
	// Draw all Entities
	for (auto& entity : entities)
	{
		entity.Draw();
	}
}