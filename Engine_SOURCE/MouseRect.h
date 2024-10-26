#pragma once
#include "MoveComponent.h"
namespace Game
{
	class MouseRect : public MoveComponent
	{
		CLONE(MoveComponent, MouseRect)
	public:
		MouseRect();
		MouseRect(const MouseRect& other);
		~MouseRect();

	public:
		void Move(float dt) override;
	};
}


