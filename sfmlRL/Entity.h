#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <exception>

class Entity
{
public:
	Entity(sf::RenderWindow& gameWindow, sf::Vector2f coords);
	void Draw();
	void Update();
	void CreateSprite(sf::Texture& texture);
protected:
	sf::Vector2f position;
	
private:
	sf::Sprite sprite;
	
	sf::RenderWindow& gameWindow;
};

