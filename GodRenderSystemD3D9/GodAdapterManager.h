#pragma once

#include "GodD3D9Prerequisites.h"

namespace GodEngine
{
	class AdapterManager
	{
	protected:
		IDirect3D9* m_parentD3D9;	// this is the parent of D3D.
	public:
		AdapterManager();

		~AdapterManager();

		bool createD3D9(); 

		bool checkDepthStencil(int adapterID,
			D3DFORMAT disForm,
			D3DFORMAT renderForm,
			D3DFORMAT stencilFmt);

		IDirect3D9* getD3D9() const { return m_parentD3D9; }
	};
}