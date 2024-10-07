#pragma once
#include "Component.h"
namespace Game
{
	class State;
	class StateController : public Component
	{
	public:
		explicit StateController(GameObject* owner);
		StateController(const StateController& other) = delete;
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


