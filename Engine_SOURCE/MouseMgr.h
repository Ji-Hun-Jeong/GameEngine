#pragma once
#include "Common.h"
#include "MouseEventReceiver.h"
namespace Game
{
	class MouseMgr
	{
		SINGLE(MouseMgr)
	public:
		void Update();
		bool GetMouseState(eButtonState isCurMouseState) 
		{ return isCurMouseState == m_MouseState; }

	private:
		eButtonState m_MouseState;
		bool m_PrevMouseClicked;

	};
}

