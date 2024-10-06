#pragma once
#include "Component.h"
namespace Game
{
	class MoveComponent : public Component
	{
	public:
		MoveComponent(GameObject* owner);
		MoveComponent(const MoveComponent& other);
		virtual ~MoveComponent();

	public:
		virtual void Move(float dt) = 0;
	};
}


