#include "EntityManager.h"

EntityManager::EntityManager(GameData& gameData)
	: gameData(gameData)
{
}

void EntityManager::LoadEntities(json jsonData)
{
	for (auto& el : jsonData.items())
	{
		std::cout << el.key() << " <-> " << el.value() << std::endl;
		json temp = el.value();
		int texture = temp.at("TextureID");
		sf::Vector2f position(temp.at("Position").at(0), temp.at("Position").at(1));
		Entity* entity = new Entity(gameData.gameWindow, position);
		entity->CreateSprite(*gameData.textures[texture]);
		entities.push_back(entity);
	}
}
