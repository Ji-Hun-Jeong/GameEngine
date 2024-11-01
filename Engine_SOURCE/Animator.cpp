#include "Animator.h"
#include "TimeMgr.h"
#include "FileMgr.h"

#include "StateController.h"
#include "State.h"
#include "Animation.h"
#include "GameObject.h"

namespace Game
{
	Animator::Animator()
		: RenderComponent()
	{
		
	}
	Animator::Animator(const Animator& other)
		: RenderComponent(other)
	{
		const std::map<std::string, Animation*>& om = other.m_MapAnimations;
		Animation* animation = nullptr;
		for (auto iter = om.begin(); iter != om.end(); ++iter)
		{
			animation = new Animation(*iter->second);
			m_MapAnimations.insert(std::make_pair(animation->GetName(), animation));
		}
	}
	Animator::~Animator()
	{
		Utility::DeleteMap<std::string, Animation*>(m_MapAnimations);
	}
	void Animator::Render(HDC dc, const TransformComponent* const transform)
	{
		const StateController* const stateController = m_Owner->GetComponent<StateController*>("StateController");
		State* curState = stateController->GetCurState();

		auto iter = m_MapAnimations.find(curState->GetName());

		Animation* const curAnimation = iter->second;

		curAnimation->Render(dc, transform);
	}
	void Animator::AddAnimation(Animation* const animation)
	{
		assert(animation);
		auto pair = m_MapAnimations.insert(std::make_pair(animation->GetName(), animation));
		assert(pair.second);
	}
}