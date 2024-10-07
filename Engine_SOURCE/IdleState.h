#pragma once
#include "State.h"
namespace Game
{
	class IdleState : public State
	{
	public:
		IdleState(StateController* owner);
		IdleState(const IdleState& other);
		~IdleState();

	public:
		void Enter() override;
		void Update() override;
		void Exit() override;
	};
}


