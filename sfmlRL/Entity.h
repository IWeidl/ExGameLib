#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <exception>

class Entity
{
public:
	Entity(sf::RenderWindow& gameWindow, std::string imagePath, sf::Vector2f coords);
	void Draw();
	void Update();
protected:
	sf::Vector2f position;
	
private:
	sf::Texture texture;
	sf::Sprite sprite;
	void LoadTexture(std::string imagePath);
	void CreateSprite();
	sf::RenderWindow& gameWindow;
};

