#pragma once
#include <sfml/Graphics.hpp>
#include <unordered_map>
namespace EGL {
	extern const std::unordered_map<std::string, sf::Keyboard::Key> StringKeyboardKeyPairs;
}