#include "GodWindow.h"
#include "GodWindowManager.h"
namespace GodEngine
{
	Window::Window()
		: m_sTitle("God Engine"),
		m_sWindowName("Default_window"),
		m_iWidth(1),
		m_iHeight(1),
		m_iXpos(0),
		m_iYpos(0)
	{

	}

	Window::Window(String winName, String title, uint32 width, uint32 height, uint32 xPos, uint32 yPos)
		: m_sWindowName(winName),
		m_sTitle(title),
		m_iWidth(width),
		m_iHeight(height),
		m_iXpos(xPos),
		m_iYpos(yPos)
	{

	}

	Window::~Window()
	{
	}
	HWND Window::getHandle() const
	{
		return m_wHandle;
	}
	bool Window::registerClass(bool bClearScreen /* = true */)
	{
		WNDCLASSEX winEx;
		ZeroMemory(&winEx, sizeof(WNDCLASSEX));

		winEx.cbSize = sizeof(WNDCLASSEX);

		winEx.style = CS_HREDRAW | CS_VREDRAW;
		winEx.lpfnWndProc = WindowManager::WinProc;
		if (bClearScreen)
		{
			winEx.hbrBackground = (HBRUSH)COLOR_WINDOW;
		}
		winEx.hInstance = (HINSTANCE)GetModuleHandle(NULL);
		winEx.hCursor = LoadCursor(NULL, IDC_ARROW);
		winEx.hIcon = LoadIcon(NULL, IDI_WINLOGO);
		winEx.lpszClassName = m_sWindowName.c_str();

		if (RegisterClassEx(&winEx))
		{
			return true;
		}
		return false;
	}

	bool Window::fullscreen(bool fScreen, uint32 width, uint32 height, uint32 bitPerPixel, DWORD &dwStyle, DWORD &dwExStyle)
	{
		bool bDisplaySettingsChanged = false;
		if (fScreen)
		{
			DEVMODE devMode;
			memset(&devMode, 0, sizeof(DEVMODE));
			devMode.dmSize = sizeof(DEVMODE);
			devMode.dmPanningWidth = static_cast<DWORD>(width);
			devMode.dmPanningHeight = static_cast<DWORD>(height);
			devMode.dmBitsPerPel = static_cast<DWORD>(bitPerPixel);
			devMode.dmFields = DM_PANNINGWIDTH | DM_PANNINGHEIGHT | DM_BITSPERPEL;

			if (ChangeDisplaySettings(&devMode, CDS_FULLSCREEN) != DISP_CHANGE_SUCCESSFUL)
			{
				MessageBox(nullptr, "Can't change to full screen", "Error", MB_OK);
				fScreen = false;
			}
			else
			{
				fScreen = true;
			}
			dwStyle = WS_POPUP;
			dwExStyle = WS_EX_APPWINDOW ;
		}
		else
		{
			dwStyle = WS_OVERLAPPEDWINDOW;
			dwExStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;
		}
		return fScreen;
	}

	int Window::adjustWindow(uint32 left, uint32 top, uint32 right, uint32 bottom, DWORD& dwStyle, DWORD &dwExStyle)
	{
		RECT winRect;
		winRect.left = (LONG)left;
		winRect.top = (LONG)top;
		winRect.right = (LONG)right;
		winRect.bottom = (LONG)bottom;

		return AdjustWindowRectEx(&winRect, dwStyle, 0, dwExStyle);
	}

	bool Window::createWindow(String winName, String title, uint32 width, uint32 height, uint32 xPos, uint32 yPos)
	{
		m_sWindowName = winName;
		m_sTitle = title;
		m_iWidth = width;
		m_iHeight = height;
		m_iXpos = xPos;
		m_iYpos = yPos;
		bool bWindowCreated = false;

		if (this->registerClass())
		{
			m_wHandle = CreateWindowEx(NULL,
				m_sWindowName.c_str(),
				m_sTitle.c_str(),
				WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS,
				m_iXpos,
				m_iYpos,
				m_iWidth,
				m_iHeight,
				NULL, NULL, (HINSTANCE)GetModuleHandle(NULL), NULL);

			if (m_wHandle != nullptr)
			{
				bWindowCreated = true;
			}
		}
		else
		{
			MessageBox(NULL, "Window did not create right.", "ERROR", MB_OK);
			bWindowCreated = false;
		}
		return bWindowCreated;
	}

	void Window::show()
	{
		if (m_wHandle)
		{
			ShowWindow(m_wHandle, SW_SHOW);
			UpdateWindow(m_wHandle);
		}
	}

	void Window::hide()
	{
		if (IsWindowVisible(m_wHandle))
		{
			ShowWindow(m_wHandle, SW_HIDE);
		}
	}

	bool Window::hasFocus() const
	{
		if (m_wHandle == GetActiveWindow())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void Window::setProcedure(WNDPROC proc)
	{
		m_wProc = proc;
	}

	void Window::setWindowName(String name)
	{
		m_sWindowName = name;
	}

	String Window::getWindowName() const
	{
		return m_sWindowName;
	}

	void Window::setWindowTitle(String title)
	{
		m_sTitle = title;
		SetWindowText(m_wHandle, m_sTitle.c_str());
	}

	String Window::getWindowTitle() const
	{
		return m_sTitle;
	}

	void Window::setWindowWidth(uint32 width)
	{
		m_iWidth = width;
	}

	uint32 Window::getWindowWidth() const
	{
		return m_iWidth;
	}

	void Window::setWindowHeight(uint32 height)
	{
		m_iHeight = height;
	}

	uint32 Window::getWindowHeight() const
	{
		return m_iHeight;
	}
}