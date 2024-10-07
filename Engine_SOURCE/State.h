#pragma once
#include "Entity.h"
#include "StateController.h"
namespace Game
{
	class State : public Entity
	{
	public:
		State(const std::string& name, StateController* owner);
		State(const State& other);
		virtual ~State();

	public:
		virtual void Enter() = 0;
		virtual void Update() = 0;
		virtual void Exit() = 0;

	protected:
		StateController* m_OwnerController;
	};
}


