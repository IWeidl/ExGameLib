#include "Game.h"
Game::Game(sf::RenderWindow& gameWindow)
	: gameWindow(gameWindow),
	gameData(gameWindow)
{
	gameData.textureManager.LoadTextures(GameData::FileToJSON("Textures.json"));
	gameData.entityManager.LoadEntities(GameData::FileToJSON("Entities.json"), gameData.textureManager.textures );
}
void Game::Draw()
{
	// Draw all Entities
	for (auto& entity : gameData.entityManager.entities)
	{
		entity->Draw();
	}
}