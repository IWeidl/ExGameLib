#pragma once
#include <SFML/Graphics.hpp>
#include <nlohmann/json.hpp>
#include <entt/entt.hpp>
#include <chaiscript/chaiscript.hpp>
#include <fstream>
#include <iostream>
#include "Toolbox.h"
#include "ScriptManager.h"
using _json = nlohmann::json;
namespace EGL
{
	class Game {
	public:
		Game();	
		
	private:
		/// <summary>
		/// Our SFML window that we draw to.
		/// </summary>
		sf::RenderWindow gameWindow;
		/// <summary>
		/// [NOT IMPLEMENTED]
		/// Our clock used for tracking dt.
		/// </summary>
		sf::Clock clock;
		int frameRate = 60;
		float dt;
		/// <summary>
		/// Handles all our scripts, what we use to create, load, and execute our scripts.
		/// </summary>
		ScriptManager scriptManager;
		/// <summary>
		/// Contains all our entity data, used extensively every frame.
		/// </summary>
		entt::registry registry;
		/// <summary>
		/// Keeps track of all actions linked to every input. 
		/// </summary>
		std::unordered_map<sf::Keyboard::Key, std::vector<std::string>> keyActionMap;
		void LoadSettings();
		/// <summary>
		/// Creates the gameWindow and sets basic properties;
		/// </summary>
		void InitializeWindow(sf::Vector2i resolution);
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
		/// <summary>
		/// Called whenever a Keypress occurs, this checks if the keypress is 'used' by an entity and if so 
		/// [PLANNED] calls the associated ChaiScript function
		/// </summary>
		/// <param name="keyEvent"></param>
		void ProcessInputs();
		/// <summary>
		/// Called every frame AFTER update, all draw calls are done here. 
		/// </summary>
		void Draw();		
	};
}
