#pragma once
#include "Components.h"
#include <chaiscript/chaiscript.hpp>
#include <entt/entt.hpp>

namespace EGL {

	class ScriptManager
	{
	public:
		ScriptManager(entt::registry& registry);
		void ExecuteSnippet(std::string snippet);	
	private:
		chaiscript::ChaiScript chai;
		entt::registry& registry;
		std::unordered_map<std::string, std::string> scripts;
		void LoadFunctions();

		// Functions to be bound to chaiscript, prepended with "s_"
		void s_Move(const std::string& entityName, const float& x, const float& y);
	};

}