#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <exception>

class Entity
{
public:
	Entity(sf::RenderWindow& gameWindow, sf::Texture& texture, sf::Vector2f coords);
	void Draw();
	void Update();
protected:
	sf::Vector2f position;
	
private:
	sf::Texture& texture;
	sf::Sprite sprite;
	void CreateSprite();
	sf::RenderWindow& gameWindow;
};

