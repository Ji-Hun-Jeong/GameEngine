#pragma once
#include "MoveComponent.h"
namespace Game
{
	class MouseUIMove : public MoveComponent
	{
		CLONE(MoveComponent, MouseUIMove)
	public:
		MouseUIMove();
		MouseUIMove(const MouseUIMove& other);
		~MouseUIMove();

	public:
		void Move(float dt) override;

	private:

	};
}


