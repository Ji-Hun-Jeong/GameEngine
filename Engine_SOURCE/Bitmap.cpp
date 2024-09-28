#include "Bitmap.h"

namespace Game
{
	HDC		Bitmap::s_MainWindowDc;
	UINT	Bitmap::s_ScreenWidth;
	UINT	Bitmap::s_ScreenHeight;
	Bitmap::Bitmap()
		: m_Bitmap{}
		, m_Dc{}
	{
		m_Bitmap = CreateCompatibleBitmap(s_MainWindowDc, s_ScreenWidth, s_ScreenHeight);
		m_Dc = CreateCompatibleDC(s_MainWindowDc);

		HBITMAP prevBitmap = static_cast<HBITMAP>(SelectObject(m_Dc, m_Bitmap));
		DeleteObject(prevBitmap);
	}
	Bitmap::~Bitmap()
	{
		DeleteDC(m_Dc);
		DeleteObject(m_Bitmap);
	}
	
}