#include "PlayerTransform.h"
#include "KeyMgr.h"
namespace Game
{
	PlayerTransform::PlayerTransform(const Math::Vector2& pos, const Math::Vector2& size)
		: TransformComponent("PlayerTransform", pos, size)
	{
		m_Pos = Math::Vector2{ 30.0f,30.0f };
		m_Size = Math::Vector2{ 100.0f,100.0f };
	}
	PlayerTransform::~PlayerTransform()
	{
	}
	void PlayerTransform::Transform(float dt)
	{
		static KeyMgr& keyMgr = KeyMgr::GetInst();
		if (keyMgr.GetKeyState(eKeyType::Left, eButtonState::Hold))
			m_Pos.x += -100.0f * dt;
		if (keyMgr.GetKeyState(eKeyType::Right, eButtonState::Hold))
			m_Pos.x += 100.0f * dt;
		if (keyMgr.GetKeyState(eKeyType::Up, eButtonState::Hold))
			m_Pos.y += -100.0f * dt;
		if (keyMgr.GetKeyState(eKeyType::Down, eButtonState::Hold))
			m_Pos.y += 100.0f * dt;
	}
	void PlayerTransform::TransformByCamera(float dt, const TransformComponent* const curCameraTransform)
	{
		Gdiplus::Rect cameraScreen = curCameraTransform->GetFinalRectInMYC();

		m_FinalPos.x = m_Pos.x - cameraScreen.X;
		m_FinalPos.y = m_Pos.y - cameraScreen.Y;
	}
	
}