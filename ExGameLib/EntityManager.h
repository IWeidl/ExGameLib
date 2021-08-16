#pragma once
#include <nlohmann/json.hpp>
#include "Entity.h"

using json = nlohmann::ordered_json;


class EntityManager
{
public:
	EntityManager(sf::RenderWindow& gameWindow);
	~EntityManager();
	std::vector<Entity*> entities;
	void LoadEntities(json jsonData, std::vector<sf::Texture*> textures);
private:
	sf::RenderWindow& gameWindow;
};

