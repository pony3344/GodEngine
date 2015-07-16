#pragma once

#include "GodD3D9Prerequisites.h"
#include "..//GodEngine/GodImage.h"

namespace GodEngine
{
	class ImageD3D9 : public Image
	{
	protected:
		D3DXIMAGE_INFO m_imageInfo;
		D3DXIMAGE_FILEFORMAT m_imageFormat;
		IDirect3DSurface9* m_Image;
		IDirect3DSurface9* m_backbuffer;
		IDirect3DDevice9* m_imageDev;
		D3DLOCKED_RECT m_lockedRect;
		bool loadImageImp(String fileName,
			Rectangle2D& srcImageRect,
			Rectangle2D& destImageRect,
			DWORD colorKey);
	public:
		ImageD3D9(IDirect3DDevice9* dev);

		~ImageD3D9();

		bool loadImage(String imageName, String fileName);
		
		void setColorKey(BYTE alpha,
			BYTE red,
			BYTE green,
			BYTE blue);

		
		void lock(void* pData, Rectangle2D& rect, int flag);

		void unlock();

		void draw();
	};
}