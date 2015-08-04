#include "GodDeviceD3D9.h"
#include "GodD3D9Utility.h"
namespace GodEngine
{
	DeviceD3D9::DeviceD3D9(IDirect3D9* d3d9)
	{
		this->m_d3d9 = d3d9;
		this->m_D3DDev9 = nullptr;
	}

	DeviceD3D9::~DeviceD3D9()
	{
		ReleaseCOM(m_D3DDev9);
	}

	bool DeviceD3D9::createDevice(HWND win, uint32 adapterID, uint32 bufferCount, uint32 width, uint32 height, bool fullScreen, bool Stencil, bool vSync, int vSynclvls, int numSamples, int Quality)
	{
		m_StencilBuffer = Stencil;
		ZeroMemory(&m_presentParams, sizeof(D3DPRESENT_PARAMETERS));

		m_presentParams.BackBufferCount = bufferCount;
		m_presentParams.BackBufferWidth = width;
		m_presentParams.BackBufferHeight = height;
		m_presentParams.Windowed = (!fullScreen);
		m_presentParams.MultiSampleType = D3D9Utility::intToD3DSAMPLETYPE(numSamples);
		m_presentParams.MultiSampleQuality = (DWORD)Quality;
		if (m_StencilBuffer)
		{
			m_presentParams.EnableAutoDepthStencil = TRUE;
			m_presentParams.AutoDepthStencilFormat = D3DFMT_D24S8;
		}
		else
		{
			m_presentParams.EnableAutoDepthStencil = FALSE;
		}

		if (vSync)
		{
			m_presentParams.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;
		}
		m_presentParams.SwapEffect = D3DSWAPEFFECT_DISCARD;
		m_presentParams.hDeviceWindow = win;

		HRESULT hr = m_d3d9->CreateDevice(adapterID,
			D3DDEVTYPE_HAL,
			win,
			D3DCREATE_HARDWARE_VERTEXPROCESSING,
			&m_presentParams,
			&m_D3DDev9);

		if (FAILED(hr))
		{
			const char* error = DXGetErrorDescription(hr);

			MessageBox(nullptr, error, "Something happened", MB_OK);
			return false;
		}
		this->m_D3DDev9->SetRenderState(D3DRS_ZENABLE, TRUE);
		this->m_D3DDev9->SetRenderState(D3DRS_LIGHTING, FALSE);
		return true;
	}

	DWORD DeviceD3D9::pickClearFlag(int flag)
	{
		DWORD dflag = 0;
		switch (flag)
		{
		case 0:
			dflag = D3DCLEAR_TARGET;
			break;
		case 1:
			dflag = D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER;
			break;
		case 2:
			if (m_StencilBuffer)
			{
				D3DCLEAR_TARGET | D3DCLEAR_STENCIL | D3DCLEAR_ZBUFFER;
			}
			break;
		}
		return dflag;
	}
	void DeviceD3D9::clear(int clearBuffer, float a, float r, float g, float b)
	{
		D3DXCOLOR color;
		color.a = a;
		color.r = r;
		color.g = g;
		color.b = b;

		m_D3DDev9->Clear(0, 0, this->pickClearFlag(clearBuffer), color, 1.0f, 1);
	}

	void DeviceD3D9::begin()
	{
		if (m_D3DDev9)
		{
			m_D3DDev9->BeginScene();
		}
	}

	void DeviceD3D9::end()
	{
		if (m_D3DDev9)
		{
			m_D3DDev9->EndScene();
		}
	}

	void DeviceD3D9::present()
	{
		if (m_D3DDev9)
		{
			m_D3DDev9->Present(0, 0, 0, 0);
		}
	}
}