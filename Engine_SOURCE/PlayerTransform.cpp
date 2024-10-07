#include "PlayerTransform.h"
#include "KeyMgr.h"
namespace Game
{
	PlayerTransform::PlayerTransform(const Math::Vector2& pos, const Math::Vector2& size)
		: TransformComponent(pos, size)
	{
		m_Pos = Math::Vector2{ 30.0f,30.0f };
		m_Size = Math::Vector2{ 100.0f,100.0f };
	}
	PlayerTransform::~PlayerTransform()
	{
	}

	void PlayerTransform::TransformByCamera(float dt, const TransformComponent* const curCameraTransform)
	{
		Gdiplus::Rect cameraScreen = curCameraTransform->GetFinalRectInMYC();

		m_FinalPos.x = m_Pos.x - cameraScreen.X;
		m_FinalPos.y = m_Pos.y - cameraScreen.Y;
	}
	
}