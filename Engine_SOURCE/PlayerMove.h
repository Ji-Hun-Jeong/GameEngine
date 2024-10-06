#pragma once
#include "MoveComponent.h"
namespace Game
{
	class PlayerMove : public MoveComponent
	{
	public:
		explicit PlayerMove(GameObject* owner);
		PlayerMove(const PlayerMove& other);
		~PlayerMove();

	public:
		void Move(float dt) override;
	};
}


