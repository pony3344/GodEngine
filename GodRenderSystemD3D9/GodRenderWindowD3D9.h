#pragma once

#include "GodD3D9Prerequisites.h"
#include "..//GodEngine/GodRenderWindow.h"

namespace GodEngine
{
	class RenderWindowD3D9 : public RenderWindow
	{
	protected:
		AdapterManager* m_adapterMgr;
		DeviceD3D9* m_device9;
	public:
		RenderWindowD3D9();

		RenderWindowD3D9(String winName, String title, uint32 width, uint32 height,
			bool fullscreen,
			bool stencil,
			bool vSync,
			uint32 vSynclvls,
			uint32 birsPerPixel,
			uint32 numSamples,
			uint32 quality);

		~RenderWindowD3D9();

		bool createRenderWindow(String winName, String winTitle, uint32 width, uint32 height, bool fullscreen, bool Stencil, bool vSync, uint32 vSynclvl, uint32 bitsPerPixel, uint32 numSamples, uint32 quality);

		void clearScene(uint32 bufferType, Real a, Real r, Real g, Real b);

		void beginRender();

		void endRender();

		void presentScene();

		DeviceD3D9* getDevice() const { return m_device9; }
	};
}