#include "ScriptManager.h"

EGL::ScriptManager::ScriptManager(entt::registry& registry)
	: registry(registry)
{
	LoadComponents();
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
	// EGL Class
	chai.add(chaiscript::var(this), "EGL");
	
	chai.add(chaiscript::fun(&ScriptManager::s_Move), "Move");
	chai.add(chaiscript::fun(&ScriptManager::s_Shift), "Shift");
	chai.add(chaiscript::fun(&ScriptManager::s_SetPos), "SetPos");
	chai.add(chaiscript::fun(&ScriptManager::s_DeleteEntity), "Delete");
	chai.add(chaiscript::fun(&ScriptManager::s_RotateEntity), "Rotate");
	chai.add(chaiscript::fun(&ScriptManager::s_AddPositionComponent), "AddPositionComponent");
}

void EGL::ScriptManager::LoadComponents()
{
	chai.add(chaiscript::user_type<MetaData>(), "MetaData");
	chai.add(chaiscript::user_type<Position>(), "Position");
	chai.add(chaiscript::user_type<Graphics>(), "Graphics");
	chai.add(chaiscript::user_type<Input>(), "Input");
}

void EGL::ScriptManager::s_Move(const std::string& entityName, const float& distance)
{
	auto view = registry.view<MetaData, Graphics, Position>();
	for (auto [_entity, _metadata, _graphics, _position] : view.each())
	{
		if (_metadata.name == entityName)
		{
			float rotation = GetRotation(_graphics.sprite);
			float dx = distance * std::cos(ToRadians(rotation));
			float dy = distance * std::sin(ToRadians(rotation));
			
			_position.x += dx;
			_position.y += dy;
		}
		
	}
}

void EGL::ScriptManager::s_Shift(const std::string& entityName, const float& x, const float& y)
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

void EGL::ScriptManager::s_AddPositionComponent(const std::string& entityName, const float& x = 0, const float& y = 0)
{
	auto view = registry.view<MetaData>();
	for (auto [_entity, _metadata] : view.each())
	{
		if (_metadata.name == entityName)
		{
			registry.emplace_or_replace<Position>(_entity, x, y);
		}
	}
}
