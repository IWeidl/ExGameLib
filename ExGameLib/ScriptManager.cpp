#include "ScriptManager.h"

EGL::ScriptManager::ScriptManager(entt::registry& registry)
	: registry(registry)
{
	LoadFunctions();
}

void EGL::ScriptManager::ExecuteSnippet(std::string snippet)
{
	try {
		chai.eval(snippet);
	}
	catch (std::exception e)
	{
		std::cout << e.what() << std::endl;
	}
}

void EGL::ScriptManager::LoadFunctions()
{
	chai.add(chaiscript::var(this), "script");
	chai.add(chaiscript::fun(&ScriptManager::s_Move), "Move");
}

void EGL::ScriptManager::s_Move(const std::string& entityName, const float& x, const float& y)
{
	auto view = registry.view<MetaData, Position>();
	for (auto [_entity, _metadata, _position] : view.each())
	{
		if (_metadata.name == entityName)
		{
			_position.x += x;
			_position.y += y;
		}
	}
}
