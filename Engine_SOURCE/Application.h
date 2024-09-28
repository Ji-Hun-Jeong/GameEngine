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

	private:
		void update();
		void postUpdate();
		void render();

	private:
		HWND m_Hwnd;
		UINT m_ScreenWidth;
		UINT m_ScreenHeight;

		HDC m_MainWindowDc;

		bool m_Run;
	};
}

