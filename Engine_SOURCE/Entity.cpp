#include "Entity.h"

namespace Game
{
	Entity::Entity(const std::string& name)
		: m_Name(name)
		, m_NameW(name.begin(), name.end())
	{}

	Entity::Entity(const Entity& other)
		: m_Name(other.m_Name)
		, m_NameW(other.m_NameW)
	{}

	Entity::~Entity()
	{
	}
}

