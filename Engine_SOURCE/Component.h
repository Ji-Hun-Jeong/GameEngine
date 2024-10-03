#pragma once
#include "GameObject.h"
namespace Game
{
	enum class eComponentType
	{
		Transform,
		End,
	};
	class Component : public Entity
	{
	public:
		Component(const std::string& name, GameObject* const owner);
		virtual ~Component() = 0;

	public:
		static Gdiplus::Rect TransformMYC(const Math::Vector2& pos, const Math::Vector2& size);

	protected:
		GameObject* m_Owner;

	};
}


