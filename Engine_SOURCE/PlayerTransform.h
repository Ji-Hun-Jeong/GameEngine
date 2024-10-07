#pragma once
#include "TransformComponent.h"
namespace Game
{
	class PlayerTransform : public TransformComponent
	{
		CLONE(TransformComponent, PlayerTransform)
	public:
		explicit PlayerTransform(const Math::Vector2& pos, const Math::Vector2& size);
		PlayerTransform(const PlayerTransform&) = default;
		~PlayerTransform();
		
	public:
		void TransformByCamera(float dt, const TransformComponent* const curCameraTransform) override;
	};
}


