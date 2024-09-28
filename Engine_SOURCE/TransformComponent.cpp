#include "TransformComponent.h"

namespace Game
{
	TransformComponent::TransformComponent(const std::string& name, GameObject* const owner)
		: Component(name, owner)
	{
	}
	TransformComponent::~TransformComponent()
	{
	}
}
