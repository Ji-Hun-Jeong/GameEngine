#pragma once
#include "TransformComponent.h"
namespace Game
{
	class PlayerTransform : public TransformComponent
	{
	public:
		explicit PlayerTransform(GameObject* const owner
			, const Math::Vector2& pos, const Math::Vector2& size);
		~PlayerTransform();
		
	public:
		void Transform(float dt) override;
		void TransformByCamera(float dt, const TransformComponent* const curCameraTransform) override;

	private:

	};
}


