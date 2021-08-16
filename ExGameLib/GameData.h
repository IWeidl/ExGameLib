#pragma once
#include <nlohmann/json.hpp>
#include <string>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <iostream>
// We need to use ordered_json, as standard json doesn't order as per file
using json = nlohmann::ordered_json;

class GameData
{
public:
	GameData(sf::RenderWindow& gameWindow);
	// Release heap memory
	~GameData();
	static json FileToJSON(std::string fileName);
	//void LoadEntities(json jsonData);
	
	sf::RenderWindow& gameWindow;
protected:
	
	
private:
	
};

