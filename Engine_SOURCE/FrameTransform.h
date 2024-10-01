#pragma once
#include "TransformComponent.h"
namespace Game
{
	class FrameTransform : public TransformComponent
	{
	public:
		FrameTransform(GameObject* const owner
			, const Math::Vector2& pos, const Math::Vector2& size);
		virtual ~FrameTransform();

	public:
		void Update(float dt) override;
		void PostUpdate(float dt, const TransformComponent* const curCameraTransform) override;
	};
}


