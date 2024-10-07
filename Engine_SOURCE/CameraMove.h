#pragma once
#include "MoveComponent.h"
namespace Game
{
	class CameraMove : public MoveComponent
	{
		CLONE(MoveComponent, CameraMove)
	public:
		CameraMove();
		CameraMove(const CameraMove& other) = default;
		~CameraMove();

	public:
		void Move(float dt) override;
	};
}


