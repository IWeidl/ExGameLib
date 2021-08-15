#pragma once
#include <nlohmann/json.hpp>
#include "Entity.h"
#include <string>
#include <fstream>
using json = nlohmann::json;
class GameData
{
public:
	GameData(sf::RenderWindow& gameWindow);
	
	static json FileToJSON(std::string fileName);
	int LoadEntity(json object, std::string entityName);
	void LoadTextures(json jsonData);

	std::vector<Entity> entities;
	std::vector<sf::Texture> textures;
	// TODO: Implement LoadEntities()
protected:
	
	
private:
	sf::RenderWindow& gameWindow;
};

