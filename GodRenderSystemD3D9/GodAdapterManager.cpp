#include "GodAdapterManager.h"

namespace GodEngine
{
	AdapterManager::AdapterManager()
	{
		m_parentD3D9 = NULL;
	}

	AdapterManager::~AdapterManager()
	{
		ReleaseCOM(m_parentD3D9);
	}

	bool AdapterManager::checkDepthStencil(int adapterID, D3DFORMAT disForm, D3DFORMAT renderForm, D3DFORMAT stencilFmt)
	{
		bool bSupported = false;

		HRESULT hr = m_parentD3D9->CheckDepthStencilMatch(adapterID, D3DDEVTYPE_HAL, disForm, renderForm, stencilFmt);
		if (FAILED(hr))
		{
			bSupported = false;
			const char* error = DXGetErrorDescription(hr);

			MessageBox(NULL, error, error, MB_OK);
		}
		else
		{
			bSupported = true;
		}
		return bSupported;
	}
	bool AdapterManager::createD3D9()
	{
		m_parentD3D9 = Direct3DCreate9(D3D_SDK_VERSION);

		if (!m_parentD3D9)
		{
			MessageBox(NULL, "Could not create D3D9", "Sorry", MB_OK);
			return false;
		}
		else
		{
			return true;
		}
		return false;
	}
}