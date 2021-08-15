#include "GameData.h"

GameData::GameData(sf::RenderWindow& gameWindow)
	: gameWindow(gameWindow)
{

}

json GameData::FileToJSON(std::string fileName)
{
	try {
		std::ifstream f(fileName, std::ifstream::in);
		json tempJson;
		f >> tempJson;
		return tempJson;
	}
	catch (std::exception e)
	{
		std::cout << e.what();
		return nullptr;
	}	
}

int GameData::LoadEntity(json object, std::string entityName)
{
	try {
		json temp = object.at(entityName);
		std::string texture = temp.at("texture");
		sf::Vector2f coords(temp.at("coords").at(0), temp.at("coords").at(1));
		Entity entity(gameWindow, texture, coords);
		entities.push_back(entity);
		return entities.size() - 1;	// Returns the index of last vector pushed back
	}
	catch (std::exception e) {
		std::cout << e.what();
		return -1;
	}
}
