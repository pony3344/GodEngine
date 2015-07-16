#include "GodRenderWindow.h"

namespace GodEngine
{
	RenderWindow::RenderWindow()
		: Window(),
		m_bFullScreen(false),
		m_bUseStencil(false),
		m_bUseVSync(false),
		m_ui32VSyncLvls(0),
		m_ui32BitsPerPixel(0),
		m_ui32NumSamples(0),
		m_ui32Quality(0)
	{

	}
	RenderWindow::RenderWindow(String winName, String title, uint32 width, uint32 height, bool fullscreen, bool stencil, bool vSync, uint32 vSynclvls, uint32 birsPerPixel, uint32 numSamples, uint32 quality)
		: Window(winName, title, width, height, 0, 0),
		m_bFullScreen(fullscreen),
		m_bUseStencil(stencil),
		m_bUseVSync(vSync),
		m_ui32VSyncLvls(vSynclvls),
		m_ui32BitsPerPixel(birsPerPixel),
		m_ui32NumSamples(numSamples),
		m_ui32Quality(quality)
	{

	}

	RenderWindow::~RenderWindow()
	{

	}

	bool RenderWindow::createRenderWindow(String winName, String winTitle, uint32 width, uint32 height, bool fullscreen, bool Stencil, bool vSync, uint32 vSynclvl, uint32 bitsPerPixel, uint32 numSamples, uint32 quality)
	{
		return true;
	}

	void RenderWindow::beginRender()
	{

	}
	void RenderWindow::endRender()
	{

	}
	void RenderWindow::presentScene()
	{

	}

	void RenderWindow::clearScene(uint32 bufferType, Real a, Real r, Real g, Real b)
	{

	}


}