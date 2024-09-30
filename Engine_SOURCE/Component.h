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

	protected:
		RECT TransformMYC(const Math::Vector2& pos, const Math::Vector2& size);
		GameObject* m_Owner;
	};
}


