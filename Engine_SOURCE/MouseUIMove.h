#pragma once
#include "UIMove.h"
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

	};
}


