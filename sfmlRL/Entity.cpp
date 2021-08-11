#include "Entity.h"


Entity::Entity(std::string imagePath, sf::Vector2i coords)
{
	position = coords;
	LoadTexture(imagePath);
	CreateSprite();
}

void Entity::Draw()
{
	// TODO: Implement drawing of entity.
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