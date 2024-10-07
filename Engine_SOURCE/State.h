#pragma once
#include "Entity.h"
#include "StateController.h"
namespace Game
{
	class State : public Entity
	{
	public:
		explicit State(const std::string& name, StateController* owner);
		State(const State& other);
		virtual ~State();

	public:
		virtual State* GetClone() const = 0;
		virtual void Enter() = 0;
		virtual void Update() = 0;
		virtual void Exit() = 0;

		void SetOwnerController(StateController* const owner) { m_OwnerController = owner; }

	protected:
		StateController* m_OwnerController;
	};
}


