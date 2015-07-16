#pragma once

#include "GodPrerequisites.h"

namespace GodEngine
{
	typedef vector<Window*> WindowVector;
	typedef WindowVector::iterator WindowIter;

	class WindowManager
	{
	protected:
		static WindowVector m_windows;
		static WindowIter m_winIter;
		static bool m_bRunning;
		static bool m_bExit;
		static MSG m_msg;
	public:
		WindowManager();

		~WindowManager();

		void addWindow(Window* win);

		Window* getWindow(String name);

		Window* getWindow(uint32 id);

		uint32 getNumWindow() const;

		void messagePump();

		void destroyWindow(String name);

		void destroyAllWindows();

		bool isRunning() const;

		void exitApp();

		static LRESULT CALLBACK WinProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);


	};
}