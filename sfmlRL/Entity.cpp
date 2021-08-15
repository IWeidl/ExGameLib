#include "Entity.h"


Entity::Entity(sf::RenderWindow& gameWindow, std::string imagePath, sf::Vector2f coords)
	: gameWindow(gameWindow)
{
	position = coords;
	LoadTexture(imagePath);
	CreateSprite();
}

void Entity::Draw()
{
	sprite.setPosition(position);
	gameWindow.draw(sprite);

}

void Entity::Update()
{
	// TODO: Implement updating of entity.
}

void Entity::LoadTexture(std::string imagePath)
{
	if (!texture.loadFromFile(imagePath))
	{
		std::cout << "ERROR: Entity::LoadTexture(): Error loading texture: " << imagePath << std::endl;
	}
	std::cout << "Successfully loaded texture: " << imagePath << std::endl;
}

void Entity::CreateSprite()
{
	sprite.setTexture(texture);
}