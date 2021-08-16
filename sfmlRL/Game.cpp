#include "Game.h"
Game::Game(sf::RenderWindow& gameWindow)
	: gameWindow(gameWindow),
	gameData(gameWindow)
{
	gameData.LoadTextures(GameData::FileToJSON("Textures.json"));
	gameData.LoadEntities(GameData::FileToJSON("Entities.json"));
}
void Game::Draw()
{
	// Draw all Entities
	for (auto& entity : gameData.entities)
	{
		entity->Draw();
	}
}