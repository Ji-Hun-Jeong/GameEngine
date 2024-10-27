#pragma once
#include "TransformComponent.h"
namespace Game
{
	class CameraTransform : public TransformComponent
	{
		CLONE(TransformComponent, CameraTransform)
	public:
		CameraTransform();
		explicit CameraTransform(const Math::Vector2& pos, const Math::Vector2& size);
		CameraTransform(const CameraTransform&) = default;
		~CameraTransform();

	public:
		void TransformByCamera(float dt, const TransformComponent* const curCameraTransform) override;
	};
}

