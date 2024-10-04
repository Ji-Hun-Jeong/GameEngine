#include "BackGroundTransform.h"

namespace Game
{
	BackGroundTransform::BackGroundTransform(const Math::Vector2& pos, const Math::Vector2& size)
		: TransformComponent("BackGroundTransform", pos, size)
	{
	}
	BackGroundTransform::~BackGroundTransform()
	{
	}
	void BackGroundTransform::Transform(float dt)
	{

	}
	void BackGroundTransform::TransformByCamera(float dt, const TransformComponent* const curCameraTransform)
	{
		Gdiplus::Rect cameraScreen = curCameraTransform->GetFinalRectInMYC();

		m_FinalPos.x = m_Pos.x - cameraScreen.X;
		m_FinalPos.y = m_Pos.y - cameraScreen.Y;
	}
}
