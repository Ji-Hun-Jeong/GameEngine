#pragma once
#include "TransformComponent.h"
namespace Game
{
	class BackGroundTransform :	public TransformComponent
	{
	public:
		explicit BackGroundTransform(GameObject* const owner
			, const Math::Vector2& pos, const Math::Vector2& size);
		~BackGroundTransform();

	public:
		void Update(float dt) override;
		void PostUpdate(float dt, const TransformComponent* const curCameraTransform) override;
	};
}


