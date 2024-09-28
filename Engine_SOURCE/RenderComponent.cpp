#include "RenderComponent.h"

namespace Game
{
	RenderComponent::RenderComponent(const std::string& name, GameObject* const owner)
		: Component(name, owner)
	{
	}
	RenderComponent::~RenderComponent()
	{
	}
	RECT RenderComponent::GetRectangle(const Math::Vector2& pos, const Math::Vector2& size)
	{
		RECT result;
		result.left = static_cast<LONG>(pos.x - size.x / 2.0f);
		result.top = static_cast<LONG>(pos.y - size.y / 2.0f);
		result.right = static_cast<LONG>(pos.x + size.x / 2.0f);
		result.bottom = static_cast<LONG>(pos.y + size.y / 2.0f);
		return result;
	}
}
