#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <unordered_map>
namespace EGL {
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
		int layer;
	};
	struct Input {
		std::unordered_map<sf::Keyboard::Key, std::string> actions;
	};
}