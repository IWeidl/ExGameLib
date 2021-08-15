#include "Game.h"
Game::Game(sf::RenderWindow& gameWindow)
	: gameWindow(gameWindow),
	gameData(gameWindow)
{
	
	gameData.LoadEntity(GameData::FileToJSON("Entities.json"), "Player");
}
void Game::Draw()
{
	// Draw all Entities
	for (Entity& entity : gameData.entities)
	{
		entity.Draw();
	}
}