#pragma once

#include "GodD3D9Prerequisites.h"
#include "..//GodEngine/GodTexture.h"

namespace GodEngine
{
	class TextureD3D9 : public Texture
	{
	protected:
		IDirect3DTexture9* m_texture;
		IDirect3DDevice9* m_texDevice;
	public:
		TextureD3D9(IDirect3DDevice9* dev);

		TextureD3D9(IDirect3DDevice9* dev,
			String texNamr,
			uint32 texWidth,
			uint32 texHeight);

		~TextureD3D9();
		
		bool createDynamicTexture(String texName,
			uint32 width,
			uint32 height,
			String format,
			bool UseMipmaps = true);

		IDirect3DTexture9* getTexture() const { return m_texture; }
	};
}