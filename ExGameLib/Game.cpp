#include "Game.h"

EGL::Game::Game()
{
	gameWindow.create(sf::VideoMode(800, 600), "GameWindow");
	gameWindow.setFramerateLimit(frameRate);

	LoadEntities("entities.json");
	
	for (auto& entity : entities)
		std::cout << entity.first << " :: " << entity.second << std::endl;

	dt = clock.getElapsedTime().asSeconds();
}

void EGL::Game::Run()
{
	while (gameWindow.isOpen())
	{
		sf::Event event;
		while (gameWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				gameWindow.close();
		}
		dt = clock.getElapsedTime().asSeconds();
		clock.restart();
		Update();
		Draw();		
	}
}

void EGL::Game::Update()
{
}

void EGL::Game::Draw()
{
	gameWindow.clear();
	gameWindow.display();
}

void EGL::Game::LoadEntities(std::string fileName)
{
	std::ifstream file(fileName);
	json entityData = json::parse(file);
	for (auto& node : entityData.items())
	{
		entities.insert({ node.key(), node.value() });
	}
}
