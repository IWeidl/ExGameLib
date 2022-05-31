#pragma once
#include <SFML/Graphics.hpp>
namespace EGL
{
	class Game {
	public:
		Game();
		void Run();
		void Update();
		void Draw();
	private:
		sf::RenderWindow gameWindow;
		sf::Clock clock;
		int frameRate = 60;
	};
}
