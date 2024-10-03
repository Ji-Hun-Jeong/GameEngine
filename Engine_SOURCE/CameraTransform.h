#pragma once
#include "TransformComponent.h"
namespace Game
{
	class CameraTransform : public TransformComponent
	{
	public:
		CameraTransform(GameObject* const owner
			, const Math::Vector2& pos, const Math::Vector2& size);
		~CameraTransform();

	public:
		void Transform(float dt) override;
		void TransformByCamera(float dt, const TransformComponent* const curCameraTransform) override;
	};
}

