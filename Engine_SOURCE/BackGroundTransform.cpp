#include "BackGroundTransform.h"

namespace Game
{
	BackGroundTransform::BackGroundTransform(GameObject* const owner
		, const Math::Vector2& pos, const Math::Vector2& size)
		: TransformComponent("BackGroundTransform", owner, pos, size)
	{
	}
	BackGroundTransform::~BackGroundTransform()
	{
	}
	void BackGroundTransform::Update(float dt)
	{
	}
}
