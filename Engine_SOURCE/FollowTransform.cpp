#include "FollowTransform.h"

namespace Game
{
	FollowTransform::FollowTransform(GameObject* const owner
		, const Math::Vector2& pos, const Math::Vector2& size)
		: TransformComponent("FollowTransform", owner, pos, size)
	{
	}
	FollowTransform::~FollowTransform()
	{
	}
	void FollowTransform::Transform(float dt)
	{
	}
	void FollowTransform::TransformByCamera(float dt, const TransformComponent* const curCameraTransform)
	{
	}
}