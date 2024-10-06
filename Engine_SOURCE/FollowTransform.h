#pragma once
#include "TransformComponent.h"
namespace Game
{
	class FollowTransform : public TransformComponent
	{
	public:
		explicit FollowTransform(GameObject* owner, const Math::Vector2& pos, const Math::Vector2& size);
		~FollowTransform();

	public:
		void TransformByCamera(float dt, const TransformComponent* const curCameraTransform) override;

	private:
		const TransformComponent* m_FollowObjectTransform;
	};
}



