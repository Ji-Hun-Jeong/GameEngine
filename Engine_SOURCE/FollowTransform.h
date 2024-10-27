#pragma once
#include "TransformComponent.h"
namespace Game
{
	class FollowTransform : public TransformComponent
	{
		CLONE(TransformComponent, FollowTransform)
	public:
		FollowTransform();
		explicit FollowTransform(const Math::Vector2& pos, const Math::Vector2& size);
		FollowTransform(const FollowTransform&) = default;
		~FollowTransform();

	public:
		void TransformByCamera(float dt, const TransformComponent* const curCameraTransform) override;

	private:
		// const TransformComponent* m_FollowObjectTransform;
	};
}



