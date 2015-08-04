#include "GodTextureD3D9.h"
#include "GodD3D9Utility.h"

namespace GodEngine
{
	TextureD3D9::TextureD3D9(IDirect3DDevice9* dev)
		: Texture()
	{
		m_texture = NULL;
		m_texDevice = dev;
	}

	TextureD3D9::TextureD3D9(IDirect3DDevice9* dev, String texNamr, uint32 texWidth, uint32 texHeight)
		: Texture(texNamr, texWidth, texHeight)
	{
		m_texDevice = dev;
		m_texture = NULL;
	}

	TextureD3D9::~TextureD3D9()
	{
		ReleaseCOM(m_texture);
	}

	bool TextureD3D9::createDynamicTexture(String texName, uint32 width, uint32 height, String format, bool UseMipmaps /* = true */)
	{
		m_texWidth = width;
		m_texHeight = height;
		m_texName = texName;
		D3DFORMAT frmt = D3D9Utility::StringToD3DFORMAT(format);
		HRESULT hr = m_texDevice->CreateTexture(
			m_texWidth,
			m_texHeight, 0,
			D3DUSAGE_DYNAMIC | D3DUSAGE_AUTOGENMIPMAP,
			frmt, D3DPOOL_DEFAULT, &m_texture, NULL);

		if (FAILED(hr))
		{
			const char* err = DXGetErrorDescription(hr);

			MessageBox(NULL, err, err, MB_OK);
			return false;
		}

		// since this is a dynamic texture (and not a render target, let's add a nice checkered pattern.
		D3DLOCKED_RECT lockRect;
		m_texture->LockRect(0, &lockRect, NULL, 0);
		DWORD* data = static_cast<DWORD*>(lockRect.pBits);

		for (uint32 i = 0; i < m_texWidth / 8; i++)
		{
			for (uint32 j = 0; j < m_texHeight / 8; j++)
			{
				int index = i * lockRect.Pitch / 4 + j;

				if ((i / 8 + j / 8) % 2 == 0)
				{
					data[index] = 0xffff0000;
				}
				else
				{
					data[index] = 0xffffffff;
				}
			}
		}
		m_texture->UnlockRect(0);
		return true;
	}
}