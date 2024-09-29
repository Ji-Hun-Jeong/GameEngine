#include "Entity.h"

namespace Game
{
	Entity::Entity(const std::string& name)
		: m_Name(name)
		, m_NameW(name.begin(), name.end())
	{}

	Entity::~Entity()
	{
	}
}

