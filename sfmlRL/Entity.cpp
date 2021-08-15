#include "Entity.h"


Entity::Entity(sf::RenderWindow& gameWindow, sf::Texture& texture, sf::Vector2f coords)
	: gameWindow(gameWindow),
	texture(texture)
{
	position = coords;
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



void Entity::CreateSprite()
{
	sprite.setTexture(texture);
}