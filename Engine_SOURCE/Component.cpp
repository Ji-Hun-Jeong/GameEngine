#include "Component.h"
namespace Game
{
	Component::Component(const std::string& name, GameObject* const owner)
		: Entity(name)
		, m_Owner(owner)
	{}
	Component::~Component()
	{
	}
	RECT Component::TransformMYC(const Math::Vector2& pos, const Math::Vector2& size)
	{
		RECT result;
		result.left = static_cast<LONG>(pos.x - size.x / 2.0f);
		result.top = static_cast<LONG>(pos.y - size.y / 2.0f);
		result.right = static_cast<LONG>(pos.x + size.x / 2.0f);
		result.bottom = static_cast<LONG>(pos.y + size.y / 2.0f);
		return result;
	}
}
