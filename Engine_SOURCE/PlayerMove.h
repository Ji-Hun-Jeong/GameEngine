#pragma once
#include "MoveComponent.h"
namespace Game
{
	class PlayerMove : public MoveComponent
	{
		CLONE(MoveComponent, PlayerMove)
	public:
		PlayerMove();
		PlayerMove(const PlayerMove& other) = default;
		~PlayerMove();

	public:
		void Move(float dt) override;
	};
}


