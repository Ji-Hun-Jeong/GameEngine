#include "FrameTransform.h"

namespace Game
{
	FrameTransform::FrameTransform(const Math::Vector2& pos, const Math::Vector2& size)
		: TransformComponent("Frame", pos, size)
	{
	}
	FrameTransform::~FrameTransform()
	{
	}
	void FrameTransform::Transform(float dt)
	{
	}
	void FrameTransform::TransformByCamera(float dt, const TransformComponent* const curCameraTransform)
	{
		Gdiplus::Rect cameraScreen = curCameraTransform->GetFinalRectInMYC();

		m_FinalPos.x = m_Pos.x - cameraScreen.X;
		m_FinalPos.y = m_Pos.y - cameraScreen.Y;
	}
}