#include "FollowTransform.h"

namespace Game
{
	FollowTransform::FollowTransform(const Math::Vector2& pos, const Math::Vector2& size)
		: TransformComponent("FollowTransform", pos, size)
		, m_FollowObjectTransform(nullptr)
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