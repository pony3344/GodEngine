#pragma once

#include "GodD3D9Prerequisites.h"

namespace GodEngine
{
	class D3D9Utility
	{
	public:
		static D3DMULTISAMPLE_TYPE intToD3DSAMPLETYPE(int numSamp);

		static D3DDECLMETHOD GodVertMethodToD3DDECLMETHOD(const GOD_VERTEX_METHOD vertMethod);

		static D3DDECLTYPE GodVertTypeToD3DDECLTYPE(const GOD_VERTEX_DATA_TYPE vertType);

		static D3DDECLUSAGE GodVertUsageToD3DDECLUSAGE(const GOD_VERTEX_USAGE_TYPE vertUsage);

		static D3DFORMAT StringToD3DFORMAT(const String fmt);
	};
}