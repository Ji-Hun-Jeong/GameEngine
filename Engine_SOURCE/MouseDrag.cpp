#include "MouseDrag.h"
#include "MouseMgr.h"
#include "TransformComponent.h"


namespace Game
{
	MouseDrag::MouseDrag(GameObject* owner)
		: MoveComponent(owner)
		, m_FinishDrag(false)
		, m_StartDrag(false)
	{
	}
	MouseDrag::MouseDrag(const MouseDrag& other)
		: MoveComponent(other)
		, m_FinishDrag(other.m_FinishDrag)
		, m_StartDrag(other.m_StartDrag)
	{
	}
	MouseDrag::~MouseDrag()
	{
	}
	void MouseDrag::Move(float dt)
	{
		TransformComponent* ownerTransform = m_Owner->GetComponent<TransformComponent*>("Transform");
		static MouseMgr& mouseMgr = MouseMgr::GetInst();
		m_FinishDrag = false;
		if (mouseMgr.GetMouseState(eButtonState::Tap))
		{
			m_StartDrag = true;
			m_FirstClickPos = mouseMgr.GetMousePos();
			m_DragingPos = m_FirstClickPos;
		}
		else if (mouseMgr.GetMouseState(eButtonState::Hold))
		{
			m_DragingPos = mouseMgr.GetMousePos();
		}
		else if (mouseMgr.GetMouseState(eButtonState::Released))
		{
			m_DragingPos = mouseMgr.GetMousePos();
			if (m_FirstClickPos != m_DragingPos)
				m_FinishDrag = true;
			m_StartDrag = false;
		}
		else
		{
			m_FirstClickPos = m_DragingPos;
		}
		ownerTransform->SetPos((m_FirstClickPos + m_DragingPos) / 2.0f);
		ownerTransform->SetSize((m_DragingPos - m_FirstClickPos).Abs());
	}
}
