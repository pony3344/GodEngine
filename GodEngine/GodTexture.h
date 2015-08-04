#pragma once

#include "GodPrerequisites.h"

namespace GodEngine
{
	class Texture
	{
	protected:
		uint32 m_texWidth;
		uint32 m_texHeight;
		uint32 m_mipMaps;
		String m_texName;
		String m_fileName;
	public:
		Texture(String texNamr,
			uint32 texWidth,
			uint32 texHeight);

		Texture();

		virtual ~Texture();

		virtual bool createDynamicTexture(String texName,
			uint32 width,
			uint32 height,
			String format,
			bool UseMipmaps = true);

	};
}