#pragma once
#include "Component.h"
namespace Game
{
	class State;
	class StateController : public Component
	{
		CLONE(StateController, StateController)
	public:
		StateController();
		StateController(const StateController& other);
		virtual ~StateController();

	public:
		void Update();
		void AddState(State* const state);
		void ChangeState(const std::string& name);

		State* GetCurState() const { return m_CurState; }

	protected:
		std::map<std::string, State*> m_MapStates;
		State* m_CurState;
	};
}


