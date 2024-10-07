#pragma once
#include "Resource.h"
#include "Bitmap.h"
namespace Game
{
	class Texture : public Resource
	{
	public:
		explicit Texture(const std::string& textureName, const std::string& fileName);
		Texture(const Texture&) = default;
		~Texture();

	public:
		HDC GetBitmapDc() { return m_ImageBitmap.GetDc(); }
		UINT GetWidth() { return m_ImageBitmap.GetWidth(); }
		UINT GetHeight() { return m_ImageBitmap.GetHeight(); }

	private:
		Bitmap m_ImageBitmap;
	};
}


