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
	}
}

