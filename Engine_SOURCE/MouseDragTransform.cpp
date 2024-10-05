#include "MouseDragTransform.h"
#include "MouseMgr.h"

namespace Game
{
	MouseDragTransform::MouseDragTransform(GameObject* owner
		, const Math::Vector2& pos, const Math::Vector2& size)
		: TransformComponent(owner, pos, size)
		, m_FinishDrag(false)
		, m_StartDrag(false)
	{
	}
	MouseDragTransform::~MouseDragTransform()
	{
	}
	void MouseDragTransform::Transform(float dt)
	{
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
		m_Pos = (m_FirstClickPos + m_DragingPos) / 2.0f;
		m_Size = (m_DragingPos - m_FirstClickPos).Abs();
	}
	void MouseDragTransform::TransformByCamera(float dt, const TransformComponent* const curCameraTransform)
	{
		m_FinalPos = m_Pos;
	}
}