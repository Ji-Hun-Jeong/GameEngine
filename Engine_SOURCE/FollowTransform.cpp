#include "FollowTransform.h"

namespace Game
{
	FollowTransform::FollowTransform(const Math::Vector2& pos, const Math::Vector2& size)
		: TransformComponent(pos, size)
		//, m_FollowObjectTransform(nullptr)
	{
	}
	FollowTransform::~FollowTransform()
	{
	}
	void FollowTransform::TransformByCamera(float dt, const TransformComponent* const curCameraTransform)
	{
	}
}