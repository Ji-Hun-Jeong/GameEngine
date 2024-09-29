#include "Bitmap.h"
#include "Application.h"

extern Game::Application* g_MyApp;
namespace Game
{
	Bitmap::Bitmap(UINT width, UINT height)
		: m_Bitmap{}
		, m_Dc{}
		, m_Width(width)
		, m_Height(height)
	{
		m_Bitmap = CreateCompatibleBitmap(g_MyApp->GetMainWindowDc(), m_Width, m_Height);
		m_Dc = CreateCompatibleDC(g_MyApp->GetMainWindowDc());

		HBITMAP prevBitmap = static_cast<HBITMAP>(SelectObject(m_Dc, m_Bitmap));
		DeleteObject(prevBitmap);
	}
	Bitmap::~Bitmap()
	{
		DeleteDC(m_Dc);
		DeleteObject(m_Bitmap);
	}
	
}