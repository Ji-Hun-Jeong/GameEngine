#include "Component.h"
namespace Game
{
	Component::Component(GameObject* owner, const std::string& name)
		: Entity(name)
		, m_Owner(owner)
	{}
	Component::Component(const Component & other)
		: Entity(other)
		, m_Owner(other.m_Owner)
	{
	}
	Component::~Component()
	{
		cout << "~Component\n";
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
