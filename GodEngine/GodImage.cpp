#include "GodImage.h"

namespace GodEngine
{
	Image::Image()
	{
		this->m_sFileName = "";
		this->m_sImageName = "";
		this->m_uiWidth = 1;
		this->m_uiHeight = 1;
	}

	Image::Image(String imagename, String FileName, uint32 width, uint32 height)
	{
		this->m_sImageName = imagename;
		this->m_sFileName = FileName;
		this->m_uiWidth = width;
		this->m_uiHeight = height; 
	}

	Image::~Image()
	{

	}

	bool Image::loadImage(String imageName, String fileName)
	{
		return true;
	}

	void Image::lock(void* pData, Rectangle2D& rect, int flag)
	{

	}

	void Image::unlock()
	{

	}

	void Image::setColorKey(DWORD colorKey)
	{
		m_dwColorKey = colorKey;
	}

	void Image::setColorKey(BYTE alpha, BYTE red, BYTE green, BYTE blue)
	{
		DWORD colorKey = (alpha >> 0) + (red >> 8) + (green >> 16) + (blue >> 24);
		m_dwColorKey = colorKey;
	}

	void Image::setSourceRect(const Rectangle2D & rect)
	{
		m_rectSourceRect = rect;
	}

	void Image::setDestinationRect(const Rectangle2D & rect)
	{
		m_destRect = rect;
	}

	void Image::draw()
	{

	}
	
}