#include "State.h"

namespace Game
{
	State::State(const std::string& name, StateController* owner)
		: Entity(name)
		, m_OwnerController(owner)
	{
	}

	State::State(const State& other)
		: Entity(other)
		, m_OwnerController(other.m_OwnerController)
	{
	}

	State::~State()
	{
	}
}

