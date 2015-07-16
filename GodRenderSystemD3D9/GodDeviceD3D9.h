#pragma once

#include "GodD3D9Prerequisites.h"

namespace GodEngine
{
	class DeviceD3D9
	{
	protected:
		IDirect3D9* m_d3d9;
		IDirect3DDevice9* m_D3DDev9;
		D3DPRESENT_PARAMETERS m_presentParams;
		DWORD pickClearFlag(int flag);
		bool m_StencilBuffer;
	public:
		DeviceD3D9(IDirect3D9* d3d9);

		~DeviceD3D9();

		bool createDevice(
			HWND win,
			uint32 adapterID,
			uint32 bufferCount,
			uint32 width,
			uint32 height,
			bool fullScreen,
			bool Stencil,
			bool vSync,
			int vSynclvls,
			int numSamples,
			int Quality);

		bool resetDeviceLost(
			HWND hwnd,
			uint32 bufferCount,
			uint32 width,
			uint32 height,
			bool fullScreen,
			bool Stencil,
			bool vSync,
			int vSynclvls,
			int numSamples,
			int Quality);

		bool resetDeviceNotLost(
			HWND hwnd,
			uint32 bufferCount,
			uint32 width,
			uint32 height,
			bool fullScreen,
			bool Stencil,
			bool vSync,
			int vSynclvls,
			int numSamples,
			int Quality);

		void clear(int clearBuffer, float a, float r, float g, float b);

		void begin();

		void end();

		void present();

		IDirect3DDevice9* getDeviceD3D9() const { return m_D3DDev9; }
	};
}