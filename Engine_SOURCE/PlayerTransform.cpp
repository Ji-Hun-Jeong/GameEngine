#include "PlayerTransform.h"
#include "KeyMgr.h"
namespace Game
{
	PlayerTransform::PlayerTransform(GameObject* const owner)
		: TransformComponent("PlayerTransform", owner)
	{
		m_Pos = Math::Vector2{ 30.0f,30.0f };
		m_Size = Math::Vector2{ 100.0f,100.0f };
	}
	PlayerTransform::~PlayerTransform()
	{
	}
	void PlayerTransform::Update()
	{
		static const float dt = 0.05f;
		static KeyMgr& keyMgr = KeyMgr::GetInst();
		if (keyMgr.GetKeyState(eKeyType::Left, eButtonState::Hold))
			m_Pos.x += -1.0f * dt;
		if (keyMgr.GetKeyState(eKeyType::Right, eButtonState::Hold))
			m_Pos.x += 1.0f * dt;
		if (keyMgr.GetKeyState(eKeyType::Up, eButtonState::Hold))
			m_Pos.y += -1.0f * dt;
		if (keyMgr.GetKeyState(eKeyType::Down, eButtonState::Hold))
			m_Pos.y += 1.0f * dt;
	}
}