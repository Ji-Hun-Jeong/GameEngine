#pragma once
#include "State.h"
namespace Game
{
	class JumpState : public State
	{
		CLONE(State, JumpState)
	public:
		JumpState(StateController* owner);
		JumpState(const JumpState& other);
		~JumpState();

	public:
		void Enter() override;
		void Update() override;
		void Exit() override;
	};
}


