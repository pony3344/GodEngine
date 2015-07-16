#pragma once

#include "GodWindowManager.h"
#include "GodWindow.h"

namespace GodEngine
{
	WindowVector WindowManager::m_windows;
	WindowIter WindowManager::m_winIter;
	bool WindowManager::m_bExit = false;
	bool WindowManager::m_bRunning = true;
	MSG WindowManager::m_msg = {};
	WindowManager::WindowManager()
	{
	}

	WindowManager::~WindowManager()
	{
	}

	void WindowManager::addWindow(Window* win)
	{
		m_windows.push_back(win);
	}

	Window* WindowManager::getWindow(String name)
	{
		Window* win = nullptr;
		m_winIter = m_windows.begin();
		while (m_winIter != m_windows.end())
		{
			win = (*m_winIter);
			if (win->getWindowName() == name)
			{
				return win;
			}
		}
		return win;
	}

	Window* WindowManager::getWindow(uint32 id)
	{
		return m_windows[id];
	}

	void WindowManager::messagePump()
	{
		Window* win = NULL;
		HWND hWnd = nullptr;
		for (m_winIter = m_windows.begin(); m_winIter != m_windows.end(); m_winIter++)
		{
			win = (*m_winIter);
			if (win != nullptr)
			{
				hWnd = win->getHandle();
			}
		}

		if (PeekMessage(&m_msg, hWnd, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&m_msg);
			DispatchMessage(&m_msg);

			if (m_msg.message == WM_QUIT || m_msg.message == WM_CLOSE)
			{
				exitApp();
			}
		}
	}

	void WindowManager::exitApp()
	{
		m_bRunning = false;
		m_bExit = true;
	}

	bool WindowManager::isRunning() const
	{
		return m_bRunning;
	}

	void WindowManager::destroyWindow(String name)
	{
		for (m_winIter = m_windows.begin(); m_winIter != m_windows.end(); ++m_winIter)
		{
			if ((*m_winIter)->getWindowName() == name)
			{
				DestroyWindow((*m_winIter)->getHandle());
				m_winIter = m_windows.erase(m_winIter);
			}
		}
	}

	void WindowManager::destroyAllWindows()
	{
		for (m_winIter = m_windows.begin(); m_winIter != m_windows.end(); ++m_winIter)
		{
			DestroyWindow((*m_winIter)->getHandle());
			m_winIter = m_windows.erase(m_winIter);
		}
	}

	LRESULT CALLBACK WindowManager::WinProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		switch (msg)
		{
		case WM_QUIT:
		case WM_CLOSE:
			m_bRunning = false;
			m_bExit = true;
			break;
		default:
			break;
		}
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}
}