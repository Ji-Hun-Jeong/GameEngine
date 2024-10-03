#pragma once
#include "TransformComponent.h"
namespace Game
{
	class FollowTransform : public TransformComponent
	{
	public:
		FollowTransform(GameObject* const owner
			, const Math::Vector2& pos, const Math::Vector2& size);
		~FollowTransform();

	public:
		void Transform(float dt) override;
		void TransformByCamera(float dt, const TransformComponent* const curCameraTransform) override;

	private:
		const TransformComponent* m_FollowObjectTransform;
	};
}



