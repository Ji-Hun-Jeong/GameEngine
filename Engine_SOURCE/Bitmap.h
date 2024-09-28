#pragma once
#include "Common.h"
namespace Game
{
	class Bitmap
	{
		friend class Application;
	public:
		Bitmap();
		~Bitmap();

	public:
		HDC& GetDc() { return m_Dc; }
		static HDC GetMainWindowDc() { return s_MainWindowDc; }
		static UINT GetScreenWidth() { return s_ScreenWidth; }
		static UINT GetScreenHeight() { return s_ScreenHeight; }

	private:
		HBITMAP m_Bitmap;
		HDC m_Dc;

		static HDC s_MainWindowDc;
		static UINT s_ScreenWidth;
		static UINT s_ScreenHeight;
	};
}


