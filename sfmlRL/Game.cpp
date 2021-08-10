#include "Game.h"
Game::Game(sf::RenderWindow& gameWindow)
	: gameWindow(gameWindow)
{
	gameData.LoadEntity(GameData::FileToJSON("Entities.json"), "Player");
}
void Game::Draw()
{
	// Draw all Entities
	for (auto& entity : gameData.entities)
	{
		entity.Draw();
	}
}