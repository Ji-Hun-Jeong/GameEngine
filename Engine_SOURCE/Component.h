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
		GameObject* m_Owner;
	};
}


