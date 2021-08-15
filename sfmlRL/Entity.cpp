#include "Entity.h"


Entity::Entity(sf::RenderWindow& gameWindow, sf::Vector2f coords)
	: gameWindow(gameWindow)
{
	position = coords;
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



void Entity::CreateSprite(sf::Texture& texture)
{
	sprite.setTexture(texture);
}