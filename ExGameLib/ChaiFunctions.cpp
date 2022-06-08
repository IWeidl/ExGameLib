#include "ChaiFunctions.h"

void EGL::s_Move(entt::registry& registry, const std::string& entityName, const float& x, const float& y)
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
