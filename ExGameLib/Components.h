#pragma once
#include <string>
#include <vector>
struct MetaData {
	std::string name;
};
struct Position {
	float x;
	float y;
};
struct Graphics {
	std::string texturePath;
	sf::Texture texture;
	sf::Sprite sprite;
};