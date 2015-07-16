#pragma once

#include "GodD3D9Prerequisites.h"

namespace GodEngine
{
	class DepthStencilBufferD3D9
	{
	protected:
		IDirect3DDevice9* m_deviceD3D9;
		IDirect3DSurface9* m_depthStencilBuffer;
		uint32 m_ui32Width;
		uint32 m_ui32Height;
	public:
		DepthStencilBufferD3D9(IDirect3DDevice9* devDepth);

		~DepthStencilBufferD3D9();

		bool createDepthStencil(
			uint32 width,
			uint32 heght,
			uint32 numSamples,
			uint32 quality);


	};
}