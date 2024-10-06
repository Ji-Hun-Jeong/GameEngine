#pragma once
#include "MoveComponent.h"
namespace Game
{
	class CameraMove : public MoveComponent
	{
	public:
		explicit CameraMove(GameObject* owner);
		CameraMove(const CameraMove& other);
		~CameraMove();

	public:
		void Move(float dt) override;
	};
}


