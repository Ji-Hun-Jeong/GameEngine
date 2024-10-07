#include "PlayerMove.h"
#include "RigidBody.h"
#include "KeyMgr.h"

namespace Game
{
	PlayerMove::PlayerMove(GameObject* owner)
		: MoveComponent(owner)
	{
	}
	PlayerMove::PlayerMove(const PlayerMove& other)
		: MoveComponent(other)
	{
	}
	PlayerMove::~PlayerMove()
	{
	}
	void PlayerMove::Move(float dt)
	{
		RigidBody* const ownerRigidBody = m_Owner->GetComponent<RigidBody*>("RigidBody");

		Vector2 f = ownerRigidBody->GetForce();
		static KeyMgr& keyMgr = KeyMgr::GetInst();
		if (keyMgr.GetKeyState(eKeyType::Left, eButtonState::Hold))
			f.x += -1000000.0f;
		if (keyMgr.GetKeyState(eKeyType::Right, eButtonState::Hold))
			f.x += 1000000.0f;
		if (keyMgr.GetKeyState(eKeyType::Up, eButtonState::Tap))
		{
			ownerRigidBody->OnGround(false);
			f.y += -1000000.0f;
		}

		ownerRigidBody->AddForce(f);
	}
}