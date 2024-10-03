#include "CameraTransform.h"
#include "KeyMgr.h"

namespace Game
{
	CameraTransform::CameraTransform(GameObject* const owner
		, const Math::Vector2& pos, const Math::Vector2& size)
		: TransformComponent("CameraTransform", owner, pos, size)
	{
	}
	CameraTransform::~CameraTransform()
	{
	}
	void CameraTransform::Transform(float dt)
	{
		KeyMgr& keyMgr = KeyMgr::GetInst();
		if (keyMgr.GetKeyState(eKeyType::A, eButtonState::Hold))
		{
			m_Pos.x += -dt * 100.0f;
		}
		if (keyMgr.GetKeyState(eKeyType::D, eButtonState::Hold))
		{
			m_Pos.x += dt * 100.0f;
		}
		if (keyMgr.GetKeyState(eKeyType::W, eButtonState::Hold))
		{
			m_Pos.y += -dt * 100.0f;
		}
		if (keyMgr.GetKeyState(eKeyType::S, eButtonState::Hold))
		{
			m_Pos.y += dt * 100.0f;
		}
	}
	void CameraTransform::TransformByCamera(float dt, const TransformComponent* const curCameraTransform)
	{
		m_FinalPos = m_Pos;
	}
}
