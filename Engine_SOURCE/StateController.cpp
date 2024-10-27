#include "StateController.h"
#include "State.h"	// 무슨 헤더파일 포함안됐다고 소멸자 안불리냐 ㅡㅡ

namespace Game
{
	StateController::StateController()
		: Component("StateController")
		, m_CurState(nullptr)
	{
	}
	StateController::StateController(const StateController& other)
		: Component(other)
		, m_CurState(nullptr)
	{
		const std::map<std::string, State*>& om = other.m_MapStates;
		State* state = nullptr;
		for (auto iter = om.begin(); iter != om.end(); ++iter)
		{
			state = iter->second->GetClone();
			state->SetOwnerController(this);
			m_MapStates.insert(std::make_pair(state->GetName(), state));
		}
		m_CurState = m_MapStates.find(other.m_CurState->GetName())->second;
	}
	StateController::~StateController()
	{
		Utility::DeleteMap<std::string, State*>(m_MapStates);
	}

	void StateController::AddState(State* const state)
	{
		auto pair = m_MapStates.insert(std::make_pair(state->GetName(), state));
		assert(pair.second);

		m_CurState = state;
	}

	void StateController::ChangeState(const std::string& name)
	{
		auto iter = m_MapStates.find(name);
		if (iter == m_MapStates.end())
			assert(0);

		m_CurState->Exit();
		m_CurState = iter->second;
		m_CurState->Enter();
	}

	void StateController::Update()
	{
		if (m_CurState)
			m_CurState->Update();
		else
			cout << "CurState Empty\n";
	}

}