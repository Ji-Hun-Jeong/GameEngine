#pragma once
#include "TransformComponent.h"
namespace Game
{
	class PlayerTransform : public TransformComponent
	{
	public:
		explicit PlayerTransform(GameObject* owner, const Math::Vector2& pos, const Math::Vector2& size);
		~PlayerTransform();
		
	public:
		void TransformByCamera(float dt, const TransformComponent* const curCameraTransform) override;
	};
}


