#include "GodDepthStencilBufferD3D9.h"
#include "GodD3D9Utility.h"

namespace GodEngine
{
	DepthStencilBufferD3D9::DepthStencilBufferD3D9(IDirect3DDevice9* devDepth)
	{
		m_deviceD3D9 = devDepth;
		m_depthStencilBuffer = nullptr;
	}

	DepthStencilBufferD3D9::~DepthStencilBufferD3D9()
	{
		ReleaseCOM(m_depthStencilBuffer);
	}

	bool DepthStencilBufferD3D9::createDepthStencil(uint32 width, uint32 heght, uint32 numSamples, uint32 quality)
	{
		HRESULT hr = m_deviceD3D9->CreateDepthStencilSurface(
			width, heght,
			D3DFMT_D24S8,
			D3D9Utility::intToD3DSAMPLETYPE(numSamples),
			(DWORD)quality, false, &m_depthStencilBuffer, nullptr);

		if (FAILED(hr))
		{
			const char* error = DXGetErrorDescription(hr);

			MessageBox(NULL, "Can't create depth Stencil", "Error", MB_OK);
			return false;
		}
		else
		{
			return true;
		}
		return true;
	}
}