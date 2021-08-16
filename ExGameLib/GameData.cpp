#include "GameData.h"

GameData::GameData(sf::RenderWindow& gameWindow)
	: gameWindow(gameWindow),
	entityManager(gameWindow),
	textureManager()
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

