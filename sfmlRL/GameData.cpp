#include "GameData.h"

GameData::GameData(sf::RenderWindow& gameWindow)
	: gameWindow(gameWindow)
{
}

GameData::~GameData()
{
	
	for (auto& texture : textures)
	{
		delete texture;
	}
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

void GameData::LoadTextures(json jsonData)
{
	
	for (auto& el : jsonData.items())
	{
		sf::Texture* texture = new sf::Texture;
		if (!texture->loadFromFile(el.value()))
		{
			std::cout << "ERROR: Entity::LoadTexture(): Error loading texture: " << el.key() << " at file path: " << el.key() << std::endl;
		}
		std::cout << "Successfully loaded texture: " << el.key() << " at file path: " << el.value() << std::endl;
		textures.push_back(texture);
	}
}
