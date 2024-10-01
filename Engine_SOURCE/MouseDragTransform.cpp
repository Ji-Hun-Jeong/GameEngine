#include "MouseDragTransform.h"
#include "MouseMgr.h"

namespace Game
{
	MouseDragTransform::MouseDragTransform(GameObject* const owner
		, const Math::Vector2& pos, const Math::Vector2& size)
		: TransformComponent("MouseDrag", owner, pos, size)
		, m_FinishDrag(false)
		, m_StartDrag(false)
	{
	}
	MouseDragTransform::~MouseDragTransform()
	{
	}
	void MouseDragTransform::Update(float dt)
	{
		m_FinishDrag = false;
		MouseMgr& mouseMgr = MouseMgr::GetInst();
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
			m_FinishDrag = true;
			m_StartDrag = false;
		}
		else
		{
			m_FirstClickPos = m_DragingPos;
		}
		m_Pos = (m_FirstClickPos + m_DragingPos) / 2.0f;
		m_Size = (m_DragingPos - m_FirstClickPos).Abs();
	}
	void MouseDragTransform::PostUpdate(float dt, const TransformComponent* const curCameraTransform)
	{
		m_FinalPos = m_Pos;
	}
}