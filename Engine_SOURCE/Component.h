#pragma once
#include "Entity.h"
namespace Game
{
	class GameObject;
	class Component : public Entity
	{
	public:
		Component(const std::string& name);
		virtual ~Component();

	public:
		virtual void DoSomething(GameObject* const owner) = 0;

	};
}


