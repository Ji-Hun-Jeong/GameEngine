#pragma once
#include "Component.h"
namespace Game
{
	class MoveComponent : public Component
	{
	public:
		MoveComponent();
		MoveComponent(const MoveComponent& other) = default;
		virtual ~MoveComponent();

	public:
		virtual MoveComponent* GetClone() const = 0;
		virtual void Move(float dt) = 0;

	};
}


