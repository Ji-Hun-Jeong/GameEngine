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
	void BackGroundTransform::PostUpdate(float dt, const TransformComponent* const curCameraTransform)
	{
		const Math::Vector2& cameraPos = curCameraTransform->GetPos();
		const Math::Vector2& cameraSize = curCameraTransform->GetSize();
		RECT newRect = TransformMYC(cameraPos, cameraSize);

		m_FinalPos.x = m_Pos.x - newRect.left;
		m_FinalPos.y = m_Pos.y - newRect.top;
	}
}
