#pragma once
#include <iostream>
#include <entt/entt.hpp>
#include "Components.h"
namespace EGL {
	// Functions to be bound to chaiscript, prepended with "s_"
	void s_Move(entt::registry& registry, const std::string& entityName, const float& x, const float& y);
}