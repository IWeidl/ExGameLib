#include "TextureManager.h"

void TextureManager::LoadTextures(json jsonData)
{
	for (auto& el : jsonData.items())
	{
		sf::Texture* texture = new sf::Texture;
		if (!texture->loadFromFile(el.value()))
		{
			std::cout << "ERROR: Entity::LoadTexture(): Error loading texture: " << el.key() << " at file path: " << el.key() << std::endl;
		}
		std::cout << "Successfully loaded texture: " << el.key() << " at file path: " << el.value() << std::endl;
		textures.push_back(texture);
	}

}
