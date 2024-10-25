#pragma once
#include "State.h"
namespace Game
{
	class WalkState : public State
	{
		CLONE(State, WalkState)
	public:
		explicit WalkState(StateController* owner);
		WalkState(const WalkState& other);
		~WalkState();

	public:
		void Enter() override;
		void Update() override;
		void Exit() override;
	};
}
