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
	chai.add(chaiscript::var(this), "EGL");
	chai.add(chaiscript::fun(&ScriptManager::s_Move), "Move");
	chai.add(chaiscript::fun(&ScriptManager::s_SetPos), "SetPos");
	chai.add(chaiscript::fun(&ScriptManager::s_DeleteEntity), "Delete");
	chai.add(chaiscript::fun(&ScriptManager::s_RotateEntity), "Rotate");
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

void EGL::ScriptManager::s_SetPos(const std::string& entityName, const float& x, const float& y)
{
	auto view = registry.view<MetaData, Position>();
	for (auto [_entity, _metadata, _position] : view.each())
	{
		if (_metadata.name == entityName)
		{
			_position.x = x;
			_position.y = y;
		}
	}
}

void EGL::ScriptManager::s_DeleteEntity(const std::string& entityName)
{
	auto view = registry.view<MetaData>();
	for (auto [_entity, _metadata] : view.each())
	{
		if (_metadata.name == entityName)
			registry.destroy(_entity);
	}
}

void EGL::ScriptManager::s_RotateEntity(const std::string& entityName, const float& angle)
{
	auto view = registry.view<MetaData, Graphics>();
	for (auto [_entity, _metadata, _graphics] : view.each())
	{
		if (_metadata.name == entityName)
		{
			_graphics.sprite.rotate(angle);
		}
	}
}
