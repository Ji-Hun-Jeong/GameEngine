#include "Component.h"
namespace Game
{
	Component::Component(const std::string& name, GameObject* const owner)
		: Entity(name)
		, m_Owner(owner)
	{}
	Component::~Component()
	{
	}
}
