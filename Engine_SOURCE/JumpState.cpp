#include "JumpState.h"
#include "RigidBody.h"

namespace Game
{
	JumpState::JumpState(StateController* owner)
		: State("Jump", owner)
	{
	}
	JumpState::JumpState(const JumpState& other)
		: State(other)
	{
		
	}
	JumpState::~JumpState()
	{
		
	}
	void JumpState::Enter()
	{
	}
	void JumpState::Update()
	{
		cout << "Jump\n";
		RigidBody* const rigidBody = GetOwnerComponent<RigidBody*>("RigidBody");
		const Math::Vector2& velocity = rigidBody->GetVelocity();
		const Math::Vector2& absVelocity = velocity.Abs();

		if (rigidBody->IsOnGround() == true)
			m_OwnerController->ChangeState("Idle");

	}
	void JumpState::Exit()
	{
	}
}
