#pragma once
#include <nlohmann/json.hpp>
#include "Entity.h"
#include "GameData.h"

using json = nlohmann::ordered_json;


class EntityManager
{
public:
	EntityManager(GameData& gameData);
	std::vector<Entity*> entities;
	void LoadEntities(json jsonData, std::vector<sf::Texture*> textures);
private:
	GameData& gameData;
};

