#pragma once
#include "TransformComponent.h"
namespace Game
{
	class BackGroundTransform :	public TransformComponent
	{
		CLONE(TransformComponent, BackGroundTransform)
	public:
		BackGroundTransform();
		explicit BackGroundTransform(const Math::Vector2& pos, const Math::Vector2& size);
		BackGroundTransform(const BackGroundTransform&) = default;
		~BackGroundTransform();

	public:
		void TransformByCamera(float dt, const TransformComponent* const curCameraTransform) override;
	};
}


