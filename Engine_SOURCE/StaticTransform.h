#pragma once
#include "TransformComponent.h"
namespace Game
{
	class StaticTransform :	public TransformComponent
	{
		CLONE(TransformComponent, StaticTransform)
	public:
		explicit StaticTransform(const Math::Vector2& pos, const Math::Vector2& size);
		StaticTransform(const StaticTransform&) = default;
		~StaticTransform();

	public:
		void TransformByCamera(float dt, const TransformComponent* const curCameraTransform) override;
	};
}


