#include "Game.h"
Game::Game(sf::RenderWindow& gameWindow)
	: gameWindow(gameWindow),
	gameData(gameWindow)
{
	gameData.textureManager.LoadTextures(GameData::FileToJSON("Textures.json"));
	gameData.entityManager.LoadEntities(GameData::FileToJSON("Entities.json"), gameData.textureManager.textures);
}
void Game::Draw()
{
	// Draw all Entities
	for (auto& entity : gameData.entityManager.entities)
	{
		entity->Draw();
	}
}

void Game::Run()
{
	while (gameWindow.isOpen())
	{
		sf::Event event;
		while (gameWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				gameWindow.close();
		}
		gameWindow.clear();
		Draw();
		gameWindow.display();

	}
}
