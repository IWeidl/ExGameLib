#pragma once
#include <nlohmann/json.hpp>
#include "Entity.h"
#include <string>
#include <fstream>

using json = nlohmann::json;
class GameData
{
public:
	std::vector<Entity> entities;
	static json FileToJSON(std::string fileName);
	int LoadEntity(json object, std::string entityName);

	// TODO: Implement LoadEntities()
protected:
	
private:
};

