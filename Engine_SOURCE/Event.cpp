#include "Event.h"

namespace Game
{
	Event::Event(const std::string& name)
		: Entity(name)
	{
	}
	Event::Event(const Entity& other)
		: Entity(other)
	{
	}
	Event::~Event()
	{

	}
}
