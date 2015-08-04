#pragma once

#include "GodD3D9Prerequisites.h"
#include "..//GodEngine/GodVertexDeclaration.h"

namespace GodEngine
{
	class VertexDeclarationD3D9 : public VertexDeclaration
	{
	protected:
		IDirect3DDevice9* m_vertDevice;
		IDirect3DVertexDeclaration9* m_vertDecl;
		IDirect3DVertexDeclaration9* updateDeclaration();
	public:
		VertexDeclarationD3D9(IDirect3DDevice9* dev9);

		VertexDeclarationD3D9(IDirect3DDevice9* dev9,String vertDeclName);

		~VertexDeclarationD3D9();

		void update();

		IDirect3DVertexDeclaration9* getVertexDecl() const;
	};
}