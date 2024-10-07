#include "WalkState.h"
#include "RigidBody.h"

namespace Game
{
	WalkState::WalkState(StateController* owner)
		: State("Walk", owner)
	{
	}
	WalkState::WalkState(const WalkState& other)
		: State(other)
	{
		
	}
	WalkState::~WalkState()
	{
		
	}
	void WalkState::Enter()
	{
	}
	void WalkState::Update()
	{
		cout << "Walk\n";
		RigidBody* const rigidBody = m_OwnerController->GetOwner()->GetComponent<RigidBody*>("RigidBody");
		const Math::Vector2& velocity = rigidBody->GetVelocity();
		const Math::Vector2& absVelocity = velocity.Abs();

		if (rigidBody->IsOnGround() == false)
			m_OwnerController->ChangeState("Jump");
		else
		{
			if (absVelocity.x == 0)
				m_OwnerController->ChangeState("Idle");
		}
	}
	void WalkState::Exit()
	{
	}
}
