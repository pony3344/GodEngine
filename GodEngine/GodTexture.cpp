#include "GodTexture.h"

namespace GodEngine
{
	Texture::Texture(String texNamr, uint32 texWidth, uint32 texHeight)
		: m_texName(texNamr),
		m_texWidth(texWidth),
		m_texHeight(texHeight),
		m_mipMaps(0),
		m_fileName(0)
	{

	}

	Texture::Texture()
		: m_texName("Default"),
		m_texWidth(1),
		m_texHeight(1),
		m_mipMaps(0),
		m_fileName("")
	{

	}

	Texture::~Texture()
	{

	}

	bool Texture::createDynamicTexture(String texName, uint32 width, uint32 height, String format, bool UseMipmaps /* = true */)
	{
		return true;
	}
}