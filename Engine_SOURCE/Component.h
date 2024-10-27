#pragma once
#include "Entity.h"
#include "Common.h"
namespace Game
{
	class Component : public Entity
	{
	public:
		Component(const std::string& name);
		Component(const Component& other);
		virtual ~Component() = 0;

	public:
		static Gdiplus::Rect GetRectInMYC(const Math::Vector2& pos, const Math::Vector2& size);
		class GameObject* GetOwner() const { return m_Owner; }
		void SetOwner(class GameObject* const owner) { m_Owner = owner; }

	protected:
		class GameObject* m_Owner;
	};
}


