#pragma once
#include "Component.h"
namespace Game
{
	class StateController : public Component
	{
		CLONE(StateController, StateController)
	public:
		StateController();
		StateController(const StateController& other);
		virtual ~StateController();

	public:
		void Update();
		void AddState(class State* const state);
		void ChangeState(const std::string& name);

		class State* GetCurState() const { return m_CurState; }

	protected:
		std::map<std::string, class State*> m_MapStates;
		class State* m_CurState;
	};
}


