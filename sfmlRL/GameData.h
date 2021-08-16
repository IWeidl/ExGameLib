#pragma once
#include <nlohmann/json.hpp>
#include "Entity.h"
#include <string>
#include <fstream>
#include <memory>

// We need to use ordered_json, as standard json doesn't order as per file
using json = nlohmann::ordered_json;

// TODO: Create EntityManager
// TODO: Create TextureManager
class GameData
{
public:
	GameData(sf::RenderWindow& gameWindow);

	// Release heap memory
	~GameData();
	static json FileToJSON(std::string fileName);
	int LoadEntity(json object, std::string entityName);
	void LoadTextures(json jsonData);
	void LoadEntities(json jsonData);
	
	// Vector of pointers to entities/textures on heap
	std::vector<Entity*> entities;
	std::vector<sf::Texture*> textures;
	// TODO: Implement LoadEntities()
protected:
	
	
private:
	sf::RenderWindow& gameWindow;
};

