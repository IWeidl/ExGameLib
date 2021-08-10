#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <exception>

class Entity
{
public:
	Entity(std::string imagePath, sf::Vector2i coords);
	void Draw();
	void Update();
protected:
	sf::Vector2i position;
	
private:
	sf::Texture texture;
	sf::Sprite sprite;
};

