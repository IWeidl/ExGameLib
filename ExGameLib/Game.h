#pragma once
#include <SFML/Graphics.hpp>
namespace EGL
{
	class Game {
	public:
		Game();
		void Run();
	protected:
		sf::RenderWindow gameWindow;
	};
}
