#include "MouseMgr.h"

namespace Game
{
	MouseMgr::MouseMgr()
		: m_MouseState(eButtonState::None)
		, m_PrevMouseClicked(false)
		, m_StartDrag(false)
		, m_FinishDrag(false)
	{}
	MouseMgr::~MouseMgr()
	{

	}
	void MouseMgr::Initalize(HWND mainWindowHwnd)
	{
		m_MainWindowHwnd = mainWindowHwnd;
	}
	void MouseMgr::Update()
	{
		if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
		{
			if (m_PrevMouseClicked)
				m_MouseState = eButtonState::Hold;
			else
				m_MouseState = eButtonState::Tap;
			m_PrevMouseClicked = true;
		}
		else
		{
			if (m_PrevMouseClicked)
				m_MouseState = eButtonState::Released;
			else
				m_MouseState = eButtonState::None;
			m_PrevMouseClicked = false;
		}
		static POINT pos;
		GetCursorPos(&pos);
		ScreenToClient(m_MainWindowHwnd, &pos);
		m_MousePos.x = static_cast<float>(pos.x);
		m_MousePos.y = static_cast<float>(pos.y);

		this->progress();

	}
	void MouseMgr::progress()
	{
		m_FinishDrag = false;
		m_PrevMousePos = m_DragingPos;
		if (GetMouseState(eButtonState::Tap))
		{
			m_StartDrag = true;
			m_FirstClickPos = m_MousePos;
			m_DragingPos = m_FirstClickPos;
		}
		else if (GetMouseState(eButtonState::Hold))
		{
			m_DragingPos = m_MousePos;
		}
		else if (GetMouseState(eButtonState::Released))
		{
			m_DragingPos = m_MousePos;
			if (m_FirstClickPos != m_DragingPos)
				m_FinishDrag = true;
			m_StartDrag = false;
		}
		else
		{
			m_FirstClickPos = m_DragingPos;
		}
	}
}

