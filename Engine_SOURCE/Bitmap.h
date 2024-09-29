#pragma once
#include "Common.h"
namespace Game
{
	class Bitmap
	{
	public:
		explicit Bitmap(UINT width, UINT height);
		~Bitmap();

	public:
		HDC& GetDc() { return m_Dc; }
		UINT GetScreenWidth() { return m_Width; }
		UINT GetScreenHeight() { return m_Height; }

	private:
		HBITMAP m_Bitmap;
		HDC m_Dc;

		UINT m_Width;
		UINT m_Height;
	};
}


