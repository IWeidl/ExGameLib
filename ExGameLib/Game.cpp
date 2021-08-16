#include "Game.h"
Game::Game(sf::RenderWindow& gameWindow)
	: gameWindow(gameWindow),
	gameData(gameWindow),
	entityManager(gameData),
	textureManager()
{
	textureManager.LoadTextures(GameData::FileToJSON("Textures.json"));
	entityManager.LoadEntities(GameData::FileToJSON("Entities.json"), textureManager.textures );
}
void Game::Draw()
{
	// Draw all Entities
	for (auto& entity : entityManager.entities)
	{
		entity->Draw();
	}
}