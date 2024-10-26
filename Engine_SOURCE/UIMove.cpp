#include "UIMove.h"
#include "UI.h"
#include "TransformComponent.h"

namespace Game
{
	UIMove::UIMove()
	{
	}
	UIMove::UIMove(const UIMove& other)
	{
	}
	UIMove::~UIMove()
	{
	}
	void UIMove::Move(float dt)
	{
		UI* const owner = static_cast<UI*>(m_Owner);	// static (x)
		UI* const ownerOfOwnerUI = owner->GetOwnerUI();

		if (ownerOfOwnerUI == nullptr)
			return;

		TransformComponent* const ownerTransform =
			owner->GetComponent<TransformComponent*>("Transform");

		TransformComponent* const ownerOfOwnerUITransform =
			ownerOfOwnerUI->GetComponent<TransformComponent*>("Transform");

		ownerTransform->SetPos(ownerOfOwnerUI->GetFinalPos());
	}
}