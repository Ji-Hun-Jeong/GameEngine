#include "MoveComponent.h"

namespace Game
{
	MoveComponent::MoveComponent(GameObject* owner)
		: Component(owner, "Move")
	{
	}
	MoveComponent::MoveComponent(const MoveComponent& other)
		: Component(other)
	{
	}
	MoveComponent::~MoveComponent()
	{
	}
}
