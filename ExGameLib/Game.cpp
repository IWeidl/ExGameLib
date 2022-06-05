#include "Game.h"

EGL::Game::Game()
{
	InitializeWindow();
	LoadEntities("entities.json");
	LoadTextures();

	dt = clock.getElapsedTime().asSeconds();
	Run();
}

void EGL::Game::InitializeWindow()
{
	gameWindow.create(sf::VideoMode(800, 600), "GameWindow");
	gameWindow.setFramerateLimit(frameRate);
}

void EGL::Game::LoadEntities(std::string fileName)
{
	std::ifstream file(fileName);
	json entityData = json::parse(file);
	for (auto& node : entityData.items())
	{
		const auto entity = registry.create();

		// Load MetaData
		registry.emplace<MetaData>(entity, node.key());

		// Load Position Component
		if (node.value().contains("position"))
		{
			json positionComponent = node.value()["position"];
			registry.emplace<Position>(entity, positionComponent[0], positionComponent[1]);
		}

		// Load Graphics Component
		if (node.value().contains("texture"))
		{
			std::string texturePath = node.value()["texture"];
			sf::Texture texture;
			sf::Sprite sprite;
			registry.emplace<Graphics>(entity, texturePath, texture, sprite);
		}

	}
}

void EGL::Game::LoadTextures()
{
	auto view = registry.view<Graphics>();
	for (auto [_entity, _graphics] : view.each())
	{
		if (!_graphics.texture.loadFromFile(_graphics.texturePath))
			std::cout << "Unable to load texture from file location: " << _graphics.texturePath << std::endl;
		_graphics.sprite.setTexture(_graphics.texture);
	}
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
	UpdateEntityPositions();
}

void EGL::Game::UpdateEntityPositions()
{
	auto view = registry.view<Position, Graphics>();
	for (auto [_entity, _position, _graphics] : view.each())
	{
		_graphics.sprite.setPosition(_position.x, _position.y);
	}
}

void EGL::Game::Draw()
{
	gameWindow.clear();

	auto view = registry.view<Graphics>();
	for (auto [_entity, _graphics] : view.each())
	{
		gameWindow.draw(_graphics.sprite);
	}

	gameWindow.display();
}

