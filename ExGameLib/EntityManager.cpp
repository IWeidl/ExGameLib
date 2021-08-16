#include "EntityManager.h"

EntityManager::EntityManager(sf::RenderWindow& gameWindow)
	: gameWindow(gameWindow)
{
}

EntityManager::~EntityManager()
{
	for (auto& entity : entities)
	{
		delete entity;
	}
}

void EntityManager::LoadEntities(json jsonData, std::vector<sf::Texture*> textures)
{
	for (auto& el : jsonData.items())
	{
		std::cout << el.key() << " <-> " << el.value() << std::endl;
		json temp = el.value();
		int texture = temp.at("TextureID");
		sf::Vector2f position(temp.at("Position").at(0), temp.at("Position").at(1));
		Entity* entity = new Entity(gameWindow, position);
		entity->CreateSprite(*textures[texture]);
		entities.push_back(entity);
	}
}
