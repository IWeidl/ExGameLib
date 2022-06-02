#pragma once
#include <SFML/Graphics.hpp>
#include <nlohmann/json.hpp>
#include <entt/entt.hpp>
#include <fstream>
#include <iostream>
using json = nlohmann::json;
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
		float dt;
		std::unordered_map<json, json> entities;
		void LoadEntities(std::string fileName);

	};
}
