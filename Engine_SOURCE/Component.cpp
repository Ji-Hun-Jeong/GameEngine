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
	Gdiplus::Rect Component::TransformMYC(const Math::Vector2& pos, const Math::Vector2& size)
	{
		Gdiplus::Rect rect;
		rect.X = static_cast<LONG>(pos.x - size.x / 2.0f);
		rect.Y = static_cast<LONG>(pos.y - size.y / 2.0f);
		rect.Width = size.x;
		rect.Height = size.y;
		return rect;
	}
}
