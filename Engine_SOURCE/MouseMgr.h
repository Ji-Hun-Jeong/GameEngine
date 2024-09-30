#pragma once
#include "Common.h"
namespace Game
{
	class MouseMgr
	{
		SINGLE(MouseMgr)
	public:
		void Initalize(HWND mainWindowHwnd);
		void Update();
		bool GetMouseState(eButtonState isCurMouseState) { return isCurMouseState == m_MouseState; }
		Math::Vector2 GetMousePos() { return m_MousePos; }

	private:
		HWND m_MainWindowHwnd;
		eButtonState m_MouseState;
		bool m_PrevMouseClicked;
		Math::Vector2 m_MousePos;
	};
}

