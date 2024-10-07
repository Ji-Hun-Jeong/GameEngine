#pragma once
#include "Common.h"
namespace Game
{
	class Bitmap
	{
	public:
		explicit Bitmap(const std::string& fileName);
		explicit Bitmap(UINT width, UINT height);
		Bitmap(const Bitmap& other) = default;
		~Bitmap();

	public:
		HDC& GetDc() { return m_Dc; }
		UINT GetWidth() { return m_Width; }
		UINT GetHeight() { return m_Height; }

	private:
		HBITMAP m_Bitmap;
		HDC m_Dc;

		UINT m_Width;
		UINT m_Height;
	};
}


