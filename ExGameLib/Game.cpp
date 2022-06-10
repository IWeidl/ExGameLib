#include "Game.h"

EGL::Game::Game()
	: scriptManager(registry)
{
	LoadSettings();
	LoadEntities("entities.json");
	LoadTextures();

	dt = clock.getElapsedTime().asSeconds();
	Run();
}

void EGL::Game::LoadSettings()
{
	// Default Settings
	sf::Vector2i resolution = { 800, 600 };
	int framerate = 60;

	std::ifstream file("settings.json");
	_json settingData = _json::parse(file);

	for (auto& node : settingData.items())
	{
		if (node.value().contains("resolution"))
			resolution = { node.value()["resolution"][0], node.value()["resolution"][1]};

		if (node.value().contains("framerate"))
			framerate = node.value()["framerate"];

	}
	InitializeWindow(resolution, framerate);
}

void EGL::Game::InitializeWindow(sf::Vector2i resolution, int framerate)
{
	gameWindow.create(sf::VideoMode(resolution.x, resolution.y), "GameWindow");
	gameWindow.setFramerateLimit(framerate);
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
				sf::Keyboard::Key key = StringKeyboardKeyPairs.at(input.key());
				actions.insert({ key, input.value()});
				if (!keyActionMap.contains(key))
					keyActionMap.insert({ key, std::vector<std::string>() });
				keyActionMap[key].push_back(input.value());
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
		_graphics.sprite.setOrigin(_graphics.sprite.getLocalBounds().width / 2, _graphics.sprite.getLocalBounds().height / 2);
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
	ProcessInputs();
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

void EGL::Game::ProcessInputs()
{
	// Loop through all currently bound keys.
	for (auto key : keyActionMap)
	{
		if (sf::Keyboard::isKeyPressed(key.first))
		{
			// Execute all actions bound to this key.
			for (auto action : key.second)
				scriptManager.ExecuteSnippet(action);
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

