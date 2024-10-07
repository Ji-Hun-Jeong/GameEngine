#pragma once
#include "TransformComponent.h"
namespace Game
{
	class FrameTransform : public TransformComponent
	{
		CLONE(TransformComponent, FrameTransform)
	public:
		explicit FrameTransform(const Math::Vector2& pos, const Math::Vector2& size);
		FrameTransform(const FrameTransform&) = default;
		virtual ~FrameTransform();

	public:
		void TransformByCamera(float dt, const TransformComponent* const curCameraTransform) override;
	};
}


