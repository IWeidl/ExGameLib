#pragma once
#include <nlohmann/json.hpp>
#include <string>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "EntityManager.h"
#include "TextureManager.h"
// We need to use ordered_json, as standard json doesn't order as per file
using json = nlohmann::ordered_json;

class GameData
{
public:
	GameData(sf::RenderWindow& gameWindow);
	static json FileToJSON(std::string fileName);
	
	EntityManager entityManager;
	TextureManager textureManager;
	sf::RenderWindow& gameWindow;
protected:
	
	
private:
	
};

