#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <exception>

class Entity
{
public:
	Entity(sf::RenderWindow& gameWindow, std::string imagePath);
	virtual void Draw() = 0;
	virtual void Update() = 0;
protected:
	sf::Vector2i position;
	
private:
	sf::RenderWindow& gameWindow;
	sf::Texture texture;
	sf::Sprite sprite;
};

