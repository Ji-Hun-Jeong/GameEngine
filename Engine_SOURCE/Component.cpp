#include "Component.h"
namespace Game
{
	Component::Component(const std::string& name)
		: Entity(name)
	{}
	Component::~Component()
	{
	}
}
