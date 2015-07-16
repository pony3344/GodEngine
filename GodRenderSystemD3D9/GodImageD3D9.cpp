#include "GodImageD3D9.h"
#include "..//GodEngine/GodRectangle2D.h"


namespace GodEngine
{
	ImageD3D9::ImageD3D9(IDirect3DDevice9* dev)
		: Image()
	{
		m_imageDev = dev;
		m_Image = nullptr; 
	}

	ImageD3D9::~ImageD3D9()
	{
		ReleaseCOM(m_Image);
		ReleaseCOM(m_backbuffer);
	}

	bool ImageD3D9::loadImage(String imageName, String fileName)
	{
		return loadImageImp(fileName,m_rectSourceRect, m_destRect, m_dwColorKey);
	}

	bool ImageD3D9::loadImageImp(String fileName, Rectangle2D& srcImageRect, Rectangle2D& destImageRect, DWORD colorKey)
	{
		RECT sourceRect;
		sourceRect.left = (LONG)srcImageRect.getLeft();
		sourceRect.top = (LONG)srcImageRect.getTop();
		sourceRect.right = (LONG)srcImageRect.getRight();
		sourceRect.bottom = (LONG)srcImageRect.getBottom();

		RECT destRect;
		destRect.left = (LONG)destImageRect.getLeft();
		destRect.top = (LONG)destImageRect.getTop();
		destRect.right = (LONG)destImageRect.getRight();
		destRect.bottom = (LONG)destImageRect.getBottom();

		HRESULT hr = D3DXGetImageInfoFromFile(fileName.c_str(), &m_imageInfo);

		
		if (SUCCEEDED(hr))
		{
			StringStream imageInfo;
			imageInfo << "Image Width: " << m_imageInfo.Width << endl;
			imageInfo << "Image Height: " << m_imageInfo.Height << endl;
			imageInfo << "Image Format: " << m_imageInfo.ImageFileFormat << endl;
			MessageBox(NULL, imageInfo.str().c_str(), "Info", MB_OK | MB_ICONINFORMATION);
		}
		m_uiWidth = m_imageInfo.Width;
		m_uiHeight = m_imageInfo.Height;
		hr = m_imageDev->CreateOffscreenPlainSurface(
			m_uiWidth,
			m_uiHeight,
			m_imageInfo.Format,
			D3DPOOL_DEFAULT,
			&m_Image,
			NULL);

		if (FAILED(hr))
		{
			const char* err = DXGetErrorDescription(hr);
			StringStream data;
			data << "Could not create off screen plain surface: " << err << endl;
			MessageBox(NULL, data.str().c_str(), data.str().c_str(), MB_OK);
		}
		hr = D3DXLoadSurfaceFromFile(m_Image, NULL, &destRect, fileName.c_str(), &sourceRect, D3DX_FILTER_NONE, colorKey, &m_imageInfo);

		if (FAILED(hr))
		{
			const char* err = DXGetErrorDescription(hr);

			StringStream errStream;
			errStream << "Cannot load image because of the following error: " << err << endl;
			MessageBox(NULL, errStream.str().c_str(), "Error", MB_OK | MB_ICONERROR);
			ReleaseCOM(m_Image);
			return false;
		}

		m_imageDev->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_MONO, &m_backbuffer);
		
		return true;
	}

	void ImageD3D9::lock(void* pData, Rectangle2D& rect, int flag)
	{
		D3DLOCKED_RECT lockedRect;
		
		RECT imageRect;
		imageRect.left = (LONG)rect.getLeft();
		imageRect.top = (LONG)rect.getTop();
		imageRect.right = (LONG)rect.getRight();
		imageRect.bottom = (LONG)rect.getBottom();

		m_Image->LockRect(&lockedRect, &imageRect, flag);
		pData = lockedRect.pBits;
		this->m_ImageData = pData;
	}

	void ImageD3D9::unlock()
	{
		m_Image->UnlockRect();
	}

	void ImageD3D9::draw()
	{
		RECT srcRect;
		srcRect.left = (LONG)m_rectSourceRect.getLeft();
		srcRect.top = (LONG)m_rectSourceRect.getTop();
		srcRect.right = (LONG)m_rectSourceRect.getRight();
		srcRect.bottom = (LONG)m_rectSourceRect.getBottom();

		RECT destRect;
		destRect.left = (LONG)m_destRect.getLeft();
		destRect.top = (LONG)m_destRect.getTop();
		destRect.right = (LONG)m_destRect.getRight();
		destRect.bottom = (LONG)m_destRect.getBottom();

		m_imageDev->StretchRect(m_Image, &srcRect, m_backbuffer, &destRect, D3DTEXF_NONE);
	}
}