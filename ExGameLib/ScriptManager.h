#pragma once
#include "entt/entt.hpp"
class ScriptManager
{
public:
	ScriptManager(entt::registry& registry);
private:
	entt::registry& registry;
};

