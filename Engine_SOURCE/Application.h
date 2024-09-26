#pragma once
#include <Common.h>
#include "GameObject.h"
namespace Game
{
	class Application
	{
	public:
		Application(HWND hwnd, UINT screenWidth, UINT m_screenHeight);
		~Application();

	public:
		void Run();

	private:
		void initalize();
		void update();
		void postUpdate();
		void render();

	private:
		HWND m_Hwnd;
		UINT m_ScreenWidth;
		UINT m_ScreenHeight;

		HDC m_MainWindowDc;

		GameObject m_GameObject;
	};
}

