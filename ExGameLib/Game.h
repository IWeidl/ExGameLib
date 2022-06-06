#pragma once
#include <SFML/Graphics.hpp>
#include <nlohmann/json.hpp>
#include <entt/entt.hpp>
#include <fstream>
#include <iostream>
#include "Components.h"
#include "Toolbox.h"
using json = nlohmann::json;
namespace EGL
{
	class Game {
	public:
		Game();	
		
	private:
		sf::RenderWindow gameWindow;
		sf::Clock clock;
		int frameRate = 60;
		float dt;
		entt::registry registry;
		/// <summary>
		/// Creates the gameWindow and sets basic properties;
		/// </summary>
		void InitializeWindow();
		/// <summary>
		/// Loads all the entities and their components from a file and adds them to the ECS registry.
		/// </summary>
		/// <param name="fileName">Path to the file.</param>
		void LoadEntities(std::string fileName);
		/// <summary>
		/// For each Graphics component, load the texture from the texturePath field and then allocate that to the sprite.
		/// </summary>
		void LoadTextures();
		/// <summary>
		/// Begins the actual game loop, calling Update() then Draw() every frame.
		/// </summary>
		void Run();
		/// <summary>
		/// Called every frame, this is where all update logic should be.
		/// </summary>
		void Update();
		/// <summary>
		/// Updates the sprite position of all entities with components: Position, Graphics
		/// </summary>
		void UpdateEntityPositions();
		void ProcessInputs();
		/// <summary>
		/// Called every frame AFTER update, all draw calls are done here. 
		/// </summary>
		void Draw();		
	};
}
