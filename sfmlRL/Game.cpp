#include "Game.h"
Game::Game(sf::RenderWindow& gameWindow)
	: gameWindow(gameWindow),
	gameData(gameWindow)
{
	gameData.LoadTextures(GameData::FileToJSON("Textures.json"));
	gameData.LoadEntity(GameData::FileToJSON("Entities.json"), "Player");
	gameData.LoadEntity(GameData::FileToJSON("Entities.json"), "Enemy");
}
void Game::Draw()
{
	// Draw all Entities
	for (auto& entity : gameData.entities)
	{
		entity->Draw();
	}
}