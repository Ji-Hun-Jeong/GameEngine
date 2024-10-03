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
		Gdiplus::Rect cameraScreen = curCameraTransform->GetFinalRectInMYC();

		m_FinalPos.x = m_Pos.x - cameraScreen.X;
		m_FinalPos.y = m_Pos.y - cameraScreen.Y;
	}
}
