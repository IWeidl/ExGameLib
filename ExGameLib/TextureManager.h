#pragma once
#include <SFML/Graphics.hpp>
#include <nlohmann/json.hpp>
#include <iostream>

using json = nlohmann::ordered_json;

class TextureManager
{
public:
	~TextureManager();
	std::vector<sf::Texture*> textures;
	void LoadTextures(json jsonData);
	
private:
};

