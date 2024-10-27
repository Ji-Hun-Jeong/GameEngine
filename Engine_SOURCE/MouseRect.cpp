#include "MouseRect.h"
#include "TransformComponent.h"
#include "MouseMgr.h"
#include "GameObject.h"

namespace Game
{
	MouseRect::MouseRect()
	{
	}
	MouseRect::MouseRect(const MouseRect& other)
	{
	}
	MouseRect::~MouseRect()
	{
	}
	void MouseRect::Move(float dt)
	{
		MouseMgr& inst = MouseMgr::GetInst();
		TransformComponent* ownerTransform = m_Owner->GetComponent<TransformComponent*>("Transform");
		ownerTransform->SetPos((inst.GetFirstClickPos() + inst.GetDraggingPos()) / 2.0f);
		ownerTransform->SetSize((inst.GetDraggingPos() - inst.GetFirstClickPos()).Abs());
	}
}
