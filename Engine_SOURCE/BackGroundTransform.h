#pragma once
#include "TransformComponent.h"
namespace Game
{
	class BackGroundTransform :	public TransformComponent
	{
	public:
		explicit BackGroundTransform(const Math::Vector2& pos, const Math::Vector2& size);
		~BackGroundTransform();

	public:
		void Transform(float dt) override;
		void TransformByCamera(float dt, const TransformComponent* const curCameraTransform) override;
	};
}


