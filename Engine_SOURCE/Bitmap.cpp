#include "Bitmap.h"
#include "Application.h"
#include "PathMgr.h"

extern Game::Application* g_MyApp;
namespace Game
{
	Bitmap::Bitmap(const std::string& fileName)
		: m_Bitmap{}
		, m_Dc(nullptr)
		, m_Width(0)
		, m_Height(0)
	{
		std::string abPath = PathMgr::GetInst().MakeAbsolutePath(fileName);

		m_Bitmap = (HBITMAP)LoadImageA(nullptr, abPath.c_str(), IMAGE_BITMAP
			, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

		assert(m_Bitmap);

		m_Dc = CreateCompatibleDC(g_MyApp->GetMainWindowDc());

		HBITMAP prevBitmap = static_cast<HBITMAP>(SelectObject(m_Dc, m_Bitmap));
		DeleteObject(prevBitmap);

		BITMAP bm;
		GetObject(m_Bitmap, sizeof(BITMAP), &bm);
		m_Width = bm.bmWidth;
		m_Height = bm.bmHeight;
	}
	Bitmap::Bitmap(UINT width, UINT height)
		: m_Bitmap{}
		, m_Dc(nullptr)
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