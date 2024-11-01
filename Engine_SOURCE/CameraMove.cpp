#include "CameraMove.h"
#include "KeyMgr.h"
#include "TransformComponent.h"
#include "GameObject.h"

namespace Game
{
	CameraMove::CameraMove()
		: MoveComponent()
	{
	}
	CameraMove::~CameraMove()
	{
	}
	void CameraMove::Move(float dt)
	{
		TransformComponent* const ownerTransform = m_Owner->GetComponent<TransformComponent*>("Transform");
		Math::Vector2 ownerPos = ownerTransform->GetPos();

		KeyMgr& keyMgr = KeyMgr::GetInst();
		if (keyMgr.GetKeyState(eKeyType::A, eButtonState::Hold))
		{
			ownerPos.x += -dt * 400.0f;
		}
		if (keyMgr.GetKeyState(eKeyType::D, eButtonState::Hold))
		{
			ownerPos.x += dt * 400.0f;
		}
		if (keyMgr.GetKeyState(eKeyType::W, eButtonState::Hold))
		{
			ownerPos.y += -dt * 400.0f;
		}
		if (keyMgr.GetKeyState(eKeyType::S, eButtonState::Hold))
		{
			ownerPos.y += dt * 400.0f;
		}

		ownerTransform->SetPos(ownerPos);
	}
}