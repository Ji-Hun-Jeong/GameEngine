#pragma once
#include "Entity.h"
namespace Game
{
	class Event : public Entity
	{
	public:
		Event(const std::string& name);
		Event(const Entity& other);
		virtual ~Event() = 0;

	public:
		virtual void Execute() = 0;

	};
}
