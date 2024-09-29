#pragma once
#include <Common.h>
namespace Game
{
	class Application
	{
	public:
		Application(HWND hwnd, UINT screenWidth, UINT m_screenHeight);
		~Application();

	public:
		void Initalize();
		bool Run();
		HDC GetMainWindowDc() { return m_MainWindowDc; }

	private:
		void update();
		void postUpdate();
		void render();

	private:
		HWND m_Hwnd;
		HDC m_MainWindowDc;
		UINT m_ScreenWidth;
		UINT m_ScreenHeight;

		bool m_Run;
	};
}

