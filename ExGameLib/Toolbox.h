#pragma once
#include <sfml/Graphics.hpp>
#include <unordered_map>
#include <numbers>

constexpr float PI = std::numbers::pi_v<float>;

namespace EGL {
	extern const std::unordered_map<std::string, sf::Keyboard::Key> StringKeyboardKeyPairs;
	float ToDegrees(float radians);
	float ToRadians(float degrees);
	/// <summary>
	/// Returns the rotation of the sprite - 90, due to SFML rotation origin being incorrect.
	/// </summary>
	/// <param name="sprite"></param>
	/// <returns></returns>
	float GetRotation(sf::Sprite& sprite);
}