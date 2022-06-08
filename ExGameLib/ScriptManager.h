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

		/// <summary>
		/// Called in the constructor, this loads all the "s_*" functions into the Chaiscript instance.
		/// </summary>
		void LoadFunctions();

		// Functions to be bound to chaiscript, prepended with "s_"
		void s_Move(const std::string& entityName, const float& x, const float& y);
	};

}