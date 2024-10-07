#include "Animator.h"
#include "TimeMgr.h"
#include "FileMgr.h"
#include "StateController.h"
#include "State.h"
#include "Animation.h"

namespace Game
{
	Animator::Animator(GameObject* owner)
		: RenderComponent(owner)
	{
		
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
		assert(iter->second);

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