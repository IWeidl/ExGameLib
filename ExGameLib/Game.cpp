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
	_json entityData = _json::parse(file);
	for (auto& node : entityData.items())
	{
		const auto entity = registry.create();

		// Load MetaData Components
		registry.emplace<MetaData>(entity, node.key());

		// Load Position Components
		if (node.value().contains("position"))
		{
			_json positionComponent = node.value()["position"];
			registry.emplace<Position>(entity, positionComponent[0], positionComponent[1]);
		}

		// Load Graphics Components
		if (node.value().contains("texture"))
		{
			std::string texturePath = node.value()["texture"];
			sf::Texture texture;
			sf::Sprite sprite;
			registry.emplace<Graphics>(entity, texturePath, texture, sprite);
		}

		// Load Input Components
		if (node.value().contains("inputs"))
		{
			_json inputComponent = node.value()["inputs"];
			std::unordered_map<sf::Keyboard::Key, std::string> actions;
			for (auto& input : inputComponent.items())
			{
				actions.insert({ StringKeyboardKeyPairs.at(input.key()), input.value()});
			}
			registry.emplace<Input>(entity, actions);
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
			else if (event.type == sf::Event::KeyPressed)
				ProcessInputs(event);
				
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

void EGL::Game::ProcessInputs(sf::Event keyEvent)
{
	auto view = registry.view<Input>();
	for (auto [_entity, _input] : view.each())
	{
		if (_input.actions.find(keyEvent.key.code) != _input.actions.end())
		{
			std::cout << _input.actions[keyEvent.key.code] << std::endl;
		}
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

