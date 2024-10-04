#include "Component.h"
namespace Game
{
	Component::Component(const std::string& name)
		: Entity(name)
	{}
	Component::Component(const Component & other)
		: Entity(other)
	{
	}
	Component::~Component()
	{
	}
	Gdiplus::Rect Component::GetRectInMYC(const Math::Vector2& pos, const Math::Vector2& size)
	{
		Gdiplus::Rect rect;
		rect.X = static_cast<INT>(pos.x - size.x / 2.0f);
		rect.Y = static_cast<INT>(pos.y - size.y / 2.0f);
		rect.Width = static_cast<INT>(size.x);
		rect.Height = static_cast<INT>(size.y);
		return rect;
	}
}
