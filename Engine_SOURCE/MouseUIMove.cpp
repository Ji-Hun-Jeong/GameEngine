#include "MouseUIMove.h"
#include "MouseMgr.h"
#include "TransformComponent.h"
#include "UI.h"

namespace Game
{
	MouseUIMove::MouseUIMove()
	{
	}
	MouseUIMove::MouseUIMove(const MouseUIMove& other)
	{
	}
	MouseUIMove::~MouseUIMove()
	{
	}
	void MouseUIMove::Move(float dt)
	{
		static MouseMgr& mouseMgr = MouseMgr::GetInst();
		UI* const owner = static_cast<UI*>(m_Owner);	// static (x)
		UI* const ownerOfOwnerUI = owner->GetOwnerUI();

		TransformComponent* const ownerTransform = 
			owner->GetComponent<TransformComponent*>("Transform");

		TransformComponent* const ownerOfOwnerUITransform =
			ownerOfOwnerUI->GetComponent<TransformComponent*>("Transform");

		ownerTransform->SetPos(ownerOfOwnerUI->GetPos());

		if (owner->IsCurFocus() == false)
			return;

		Math::Vector2 curFrameOffset = mouseMgr.GetMousePos() - mouseMgr.GetPrevMousePos();
		if (mouseMgr.GetMouseState(eButtonState::Hold))
		{
			ownerTransform->SetPos(ownerTransform->GetPos() + curFrameOffset);
			ownerOfOwnerUITransform->SetPos(ownerOfOwnerUITransform->GetPos() + curFrameOffset);
		}

	}
}