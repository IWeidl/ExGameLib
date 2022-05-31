#include "Game.h"

EGL::Game::Game()
{
	gameWindow.create(sf::VideoMode(800, 600), "GameWindow");
	gameWindow.setFramerateLimit(frameRate);
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
