#include "PlayerTransform.h"

namespace Game
{
	PlayerTransform::PlayerTransform()
		: PlayerTransform(Math::Vector2(), Math::Vector2())
	{

	}
	PlayerTransform::PlayerTransform(const Math::Vector2& pos, const Math::Vector2& size)
		: TransformComponent(pos, size)
	{
		
	}
	PlayerTransform::~PlayerTransform()
	{
	}

	void PlayerTransform::TransformByCamera(float dt, const TransformComponent* const curCameraTransform)
	{
		Gdiplus::Rect cameraScreen = curCameraTransform->GetFinalRectInMYC();

		m_FinalPos.x += m_Pos.x - cameraScreen.X;
		m_FinalPos.y += m_Pos.y - cameraScreen.Y;
	}
	
}