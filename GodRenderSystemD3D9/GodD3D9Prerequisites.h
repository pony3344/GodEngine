#pragma once

#if defined(DEBUG) || defined(_DEBUG)
#ifndef D3D_DEBUG_INFO
#define D3D_DEBUG_INFO
#endif
#endif

#include "..//GodEngine/GodPrerequisites.h"

#include <d3d9.h>
#include <d3dx9.h>
#include <DxErr.h>

#pragma comment(lib,"x86/d3d9.lib")
#pragma comment(lib,"x86/d3dx9.lib")
#pragma comment(lib,"x86/dxerr.lib")

#define ReleaseCOM(x) { if(x){x->Release(); x=0; } }

namespace GodEngine
{
	class AdapterD3D9;
	class AdapterManager;
	class DeviceD3D9;
	class DepthStencilBufferD3D9;
	class DisplayMode;
	class D3D9Utility;
	class ImageD3D9;
	class RenderWindowD3D9;
}