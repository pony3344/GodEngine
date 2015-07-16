#pragma once

#include "GodPrerequisites.h"

namespace GodEngine
{
	class Window
	{
	protected:
		uint32 m_iWidth;
		uint32 m_iHeight;
		uint32 m_iXpos;
		uint32 m_iYpos;
		String m_sWindowName;
		String m_sTitle;
		HWND m_wHandle;
		WNDPROC m_wProc;
		bool registerClass(bool bClearScreen = true);
		bool fullscreen(
			bool fScreen, 
			uint32 width, 
			uint32 height, 
			uint32 bitPerPixel,
			DWORD &dwStyle, 
			DWORD &dwExStyle);
		int adjustWindow(
			uint32 left, 
			uint32 top, 
			uint32 right, 
			uint32 bottom, 
			DWORD &dwStyle, 
			DWORD &dwExStyle);

	public:
		Window();

		Window(
			String winName,
			String title,
			uint32 width,
			uint32 height,
			uint32 xPos,
			uint32 yPos);

		virtual ~Window();

		virtual bool createWindow(
			String winName,
			String title,
			uint32 width,
			uint32 height,
			uint32 xPos,
			uint32 yPos);

		void show();

		void hide();

		bool isHidden() const;

		bool isShowing() const;

		bool hasFocus() const;

		void setWindowTitle(String title);

		String getWindowTitle() const;

		void setWindowName(String name);

		String getWindowName() const;

		void setWindowWidth(uint32 width);

		uint32 getWindowWidth() const;

		void setWindowHeight(uint32 height);

		uint32 getWindowHeight() const;

		HWND getHandle() const;

		void setProcedure(WNDPROC proc);

	};
}