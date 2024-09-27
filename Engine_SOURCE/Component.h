#pragma once
#include "Entity.h"
namespace Game
{
	class Component : public Entity
	{
	public:
		Component(const std::string& name);
		virtual ~Component();

	public:
		virtual void DoSomething(class GameObject* const owner) = 0;

	};
}


