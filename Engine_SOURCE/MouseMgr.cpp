#include "MouseMgr.h"

namespace Game
{
	MouseMgr::MouseMgr()
		: m_MouseState(eButtonState::None)
		, m_PrevMouseClicked(false)
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
	}
}

