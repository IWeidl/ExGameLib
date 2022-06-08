#pragma once
#include "Components.h"
#include <chaiscript/chaiscript.hpp>
#include <entt/entt.hpp>
#include <initializer_list>

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
		void LoadComponents();
		/*
		* Functions to be bound to chaiscript, prepended with "s_"
		*/

		/// <summary>
		/// Moves an entity by x and y.
		/// </summary>
		/// <param name="entityName"></param>
		/// <param name="x"></param>
		/// <param name="y"></param>
		void s_Move(const std::string& entityName, const float& x, const float& y);
		/// <summary>
		/// Sets an enity's location (x, y).
		/// </summary>
		/// <param name="entityName"></param>
		/// <param name="x"></param>
		/// <param name="y"></param>
		void s_SetPos(const std::string& entityName, const float& x, const float& y);
		/// <summary>
		/// Deletes all entities with entityName.
		/// </summary>
		/// <param name="entityName"></param>
		void s_DeleteEntity(const std::string& entityName);
		/// <summary>
		/// Rotates an entity by x degrees.
		/// </summary>
		/// <param name="entityName"></param>
		/// <param name="angle"></param>
		void s_RotateEntity(const std::string& entityName, const float& angle);
	};

}