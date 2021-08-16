#include "Game.h"
Game::Game(sf::RenderWindow& gameWindow)
	: gameWindow(gameWindow),
	gameData(gameWindow),
	entityManager(gameData)
{
	gameData.LoadTextures(GameData::FileToJSON("Textures.json"));
	entityManager.LoadEntities(GameData::FileToJSON("Entities.json"));
}
void Game::Draw()
{
	// Draw all Entities
	for (auto& entity : entityManager.entities)
	{
		entity->Draw();
	}
}