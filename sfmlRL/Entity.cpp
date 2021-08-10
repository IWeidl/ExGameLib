#include "Entity.h"

Entity::Entity(sf::RenderWindow& gameWindow, std::string imagePath)
	: gameWindow(gameWindow)
{
	try {
		texture.loadFromFile(imagePath);
	}
	catch (const std::exception& e) {
		std::cout << e.what();
	}
}

void Entity::Draw()
{
	// TODO: Implement drawing of entity.
}

void Entity::Update()
{
	// TODO: Implement updating of entity.
}