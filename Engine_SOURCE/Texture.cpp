#include "Texture.h"
#include "PathMgr.h"

namespace Game
{
	Texture::Texture(const std::string& textureName, const std::string& fileName)
		: Resource(textureName)
		, m_ImageBitmap(fileName)
	{

	}
	Texture::~Texture()
	{
	}
}
