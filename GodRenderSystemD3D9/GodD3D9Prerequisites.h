#pragma once



#include "..//GodEngine/GodPrerequisites.h"

#include <d3d9.h>
#include <d3dx9.h>
#include <DxErr.h>

#pragma comment(lib,"x86/d3d9.lib")
#if defined(DEBUG) | defined(_DEBUG)
#pragma comment(lib,"x86/d3dx9d.lib")
#else
#pragma comment(lib,"x86/d3dx9.lib")
#endif
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
	class TextureD3D9;
	class VertexDeclarationD3D9;
	class RenderWindowD3D9;
}