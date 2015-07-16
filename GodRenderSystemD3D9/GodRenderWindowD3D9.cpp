#include "GodRenderWindowD3D9.h"
#include "GodAdapterManager.h"
#include "GodDeviceD3D9.h"

namespace GodEngine
{
	RenderWindowD3D9::RenderWindowD3D9()
		: RenderWindow()
	{
		this->m_adapterMgr = new AdapterManager();
		this->m_adapterMgr->createD3D9();
		this->m_device9 = new DeviceD3D9(m_adapterMgr->getD3D9());
	}

	RenderWindowD3D9::RenderWindowD3D9(String winName, String title, uint32 width, uint32 height, bool fullscreen, bool stencil, bool vSync, uint32 vSynclvls, uint32 birsPerPixel, uint32 numSamples, uint32 quality)
		: RenderWindow(winName, title, width, height, fullscreen, stencil, vSync, vSynclvls, birsPerPixel, numSamples, quality)
	{
		this->m_adapterMgr = new AdapterManager();
		this->m_adapterMgr->createD3D9();
		this->m_device9 = new DeviceD3D9(m_adapterMgr->getD3D9());
	}

	RenderWindowD3D9::~RenderWindowD3D9()
	{
		ReleaseClass(m_device9);
		ReleaseClass(m_adapterMgr);
	}

	bool RenderWindowD3D9::createRenderWindow(String winName, String winTitle, uint32 width, uint32 height, bool fullscreen, bool Stencil, bool vSync, uint32 vSynclvl, uint32 bitsPerPixel, uint32 numSamples, uint32 quality)
	{
		m_sWindowName = winName;
		m_sTitle = winTitle;
		this->m_iWidth = width;
		this->m_iHeight = height;
		m_bFullScreen = fullscreen;
		this->m_bUseStencil = Stencil;
		this->m_bUseVSync = vSync;
		this->m_ui32VSyncLvls = vSynclvl;
		this->m_ui32BitsPerPixel = bitsPerPixel;
		this->m_ui32NumSamples = numSamples;
		this->m_ui32Quality = quality;
		this->registerClass();

		DWORD dwStyle = 0;
		DWORD dwExStyle = 0;
		this->fullscreen(fullscreen, m_iWidth, m_iHeight, m_ui32BitsPerPixel, dwStyle, dwExStyle);
		this->adjustWindow(0, 0, m_iWidth, m_iHeight, dwStyle, dwExStyle);

		this->m_wHandle = CreateWindowEx(dwExStyle,
			m_sWindowName.c_str(),
			m_sTitle.c_str(),
			dwStyle,
			0, 0, m_iWidth, m_iHeight, NULL, NULL, GetModuleHandle(NULL), NULL);

		if (m_wHandle != nullptr && m_device9->createDevice(m_wHandle, 0, 1, m_iWidth, m_iHeight, m_bFullScreen, m_bUseStencil, m_bUseVSync, m_ui32VSyncLvls, m_ui32NumSamples, m_ui32Quality))
		{
			return true;
		}
		else
		{
			return false;
		}
		return false;
	}

	void RenderWindowD3D9::clearScene(uint32 bufferType, Real a, Real r, Real g, Real b)
	{
		if (m_device9)
		{
			m_device9->clear((unsigned int)bufferType, a, r, g, b);
		}
	}

	void RenderWindowD3D9::beginRender()
	{
		if (m_device9)
		{
			m_device9->begin();
		}
	}

	void RenderWindowD3D9::endRender()
	{
		if (m_device9)
		{
			m_device9->end();
		}
	}

	void RenderWindowD3D9::presentScene()
	{
		if (m_device9)
		{
			m_device9->present();
		}
	}
}