#pragma once
#include "MoveComponent.h"
namespace Game
{
	class UIMove : public MoveComponent
	{
		CLONE(MoveComponent, UIMove)
	public:
		UIMove();
		UIMove(const UIMove& other);
		~UIMove();

	public:
		void Move(float dt) override;

	};
}


