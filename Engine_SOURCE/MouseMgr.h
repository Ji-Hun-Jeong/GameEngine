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

		Math::Vector2 GetMousePos() { return m_MousePos; }
		Math::Vector2 GetDraggingPos() { return m_DragingPos; }
		Math::Vector2 GetPrevMousePos() { return m_PrevMousePos; }
		Math::Vector2 GetFirstClickPos() { return m_FirstClickPos; }

		bool GetMouseState(eButtonState isCurMouseState) { return isCurMouseState == m_MouseState; }
		bool IsStartDraging() { return m_StartDrag; }
		bool IsReleased() { return m_FinishDrag; }

	private:
		void progress();

	private:
		HWND m_MainWindowHwnd;
		eButtonState m_MouseState;

		Math::Vector2 m_MousePos;
		Math::Vector2 m_FirstClickPos;
		Math::Vector2 m_PrevMousePos;
		Math::Vector2 m_DragingPos;

		bool m_PrevMouseClicked;
		bool m_StartDrag;
		bool m_FinishDrag;
	};
}

