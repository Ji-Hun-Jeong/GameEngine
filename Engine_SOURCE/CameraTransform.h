#pragma once
#include "TransformComponent.h"
namespace Game
{
	class CameraTransform : public TransformComponent
	{
	public:
		explicit CameraTransform(GameObject* owner, const Math::Vector2& pos, const Math::Vector2& size);
		~CameraTransform();

	public:
		void TransformByCamera(float dt, const TransformComponent* const curCameraTransform) override;
	};
}

