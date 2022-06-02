#include "Game.h"

EGL::Game::Game()
{
	gameWindow.create(sf::VideoMode(800, 600), "GameWindow");
	gameWindow.setFramerateLimit(frameRate);

	LoadEntities("entities.json");

	auto view = registry.view<MetaData, Position>();
	for (auto [entity, metadata, position] : view.each())
	{
		std::cout << metadata.name << " at position: " << position.x << " " << position.y << std::endl;
	}

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
		const auto entity = registry.create();

		// Save MetaData
		registry.emplace<MetaData>(entity, node.key());

		// Save Position
		if (node.value().contains("position"))
		{
			json positionComponent = node.value()["position"];
			registry.emplace<Position>(entity, positionComponent[0], positionComponent[1]);
		}
			
	}
}
