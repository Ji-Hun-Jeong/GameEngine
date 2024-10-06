#pragma once
#include "TransformComponent.h"
namespace Game
{
	class FrameTransform : public TransformComponent
	{
	public:
		explicit FrameTransform(GameObject* owner, const Math::Vector2& pos, const Math::Vector2& size);
		virtual ~FrameTransform();

	public:
		void TransformByCamera(float dt, const TransformComponent* const curCameraTransform) override;
	};
}


