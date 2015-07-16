#pragma once

#include "GodPrerequisites.h"
#include "GodRectangle2D.h"
namespace GodEngine
{
	class Image
	{
	protected:
		uint32 m_uiWidth;
		uint32 m_uiHeight;
		String m_sFileName;
		String m_sImageName;
		void* m_ImageData;
		uint32 m_ui32Pitch;
		DWORD m_dwColorKey;
		Rectangle2D m_rectSourceRect;
		Rectangle2D m_destRect;
	public:
		Image();

		Image(String imagename, String FileName,
			uint32 width,
			uint32 height);

		virtual ~Image();

		virtual bool loadImage(String imageName,
			String fileName);

		virtual void lock(void* pData, Rectangle2D& rect, int flag);

		virtual void unlock();

		virtual void draw();

		void setColorKey(BYTE alpha,
			BYTE red,
			BYTE green,
			BYTE blue);

		void setColorKey(DWORD colorKey);

		void setSourceRect(const Rectangle2D & rect);

		void setDestinationRect(const Rectangle2D & rect);

		Rectangle2D getSourceRectangle() const { return m_rectSourceRect; }

		Rectangle2D getDestRectangle() const { return m_destRect; }

		uint32 getWidth() const { return m_uiWidth; }

		uint32 getHeight() const { return m_uiHeight; }

		String getImageName() const { return m_sImageName; }

		void* getImageData() const { return m_ImageData; }

		uint32 getPitch() const { return m_ui32Pitch; }
	};
}