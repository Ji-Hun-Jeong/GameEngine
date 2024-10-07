#pragma once
#include "GameObject.h"
namespace Game
{
	class Component : public Entity
	{
	public:
		Component(GameObject* owner, const std::string& name);
		Component(const Component& other);
		virtual ~Component() = 0;

	public:
		static Gdiplus::Rect GetRectInMYC(const Math::Vector2& pos, const Math::Vector2& size);
		GameObject* GetOwner() const { return m_Owner; }

	protected:
		GameObject* m_Owner;
	};
}


