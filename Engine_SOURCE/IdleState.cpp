#include "IdleState.h"
#include "RigidBody.h"

namespace Game
{
	IdleState::IdleState(StateController* owner)
		: State("Idle", owner)
	{
	}
	IdleState::IdleState(const IdleState& other)
		: State(other)
	{
		
	}
	IdleState::~IdleState()
	{
		
	}
	void IdleState::Enter()
	{
	}
	void IdleState::Update()
	{
		cout << "Idle\n";
		RigidBody* const rigidBody = GetOwnerComponent<RigidBody*>("RigidBody");
		const Math::Vector2& velocity = rigidBody->GetVelocity();
		const Math::Vector2& absVelocity = velocity.Abs();

		if (rigidBody->IsOnGround() == false)
			m_OwnerController->ChangeState("Jump");
		else
		{
			if (absVelocity.x > 0)
				m_OwnerController->ChangeState("Walk");
		}
	}
	void IdleState::Exit()
	{
	}
}
