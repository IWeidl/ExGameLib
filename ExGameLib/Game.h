#pragma once
#include <SFML/Graphics.hpp>
#include <nlohmann/json.hpp>
#include <entt/entt.hpp>
#include <fstream>
#include <iostream>
#include "Components.h"
using json = nlohmann::json;
namespace EGL
{
	class Game {
	public:
		Game();
		void Run();
		
	private:
		sf::RenderWindow gameWindow;
		sf::Clock clock;
		int frameRate = 60;
		float dt;
		entt::registry registry;
		/// <summary>
		/// Loads all the entities and their components from a file and adds them to the ECS registry.
		/// </summary>
		/// <param name="fileName">Path to the file.</param>
		void LoadEntities(std::string fileName);
		/// <summary>
		/// For each Graphics component, load the texture from the texturePath field and then allocate that to the sprite.
		/// </summary>
		void LoadTextures();
		void Update();
		void Draw();
	};
}
