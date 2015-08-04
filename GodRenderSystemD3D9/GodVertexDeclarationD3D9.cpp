#include "GodVertexDeclarationD3D9.h"
#include "GodD3D9Utility.h"
#include "..//GodEngine/GodVertexElement.h"

namespace GodEngine
{
	VertexDeclarationD3D9::VertexDeclarationD3D9(IDirect3DDevice9* dev)
		: VertexDeclaration()
	{
		this->m_vertDevice = dev;
		m_vertDecl = NULL;
	}

	VertexDeclarationD3D9::VertexDeclarationD3D9(IDirect3DDevice9* dev9, String vertDeclName)
		: VertexDeclaration(vertDeclName)
	{
		this->m_vertDevice = dev9;
		m_vertDecl = NULL;
	}

	VertexDeclarationD3D9::~VertexDeclarationD3D9()
	{
		ReleaseCOM(m_vertDecl);
	}

	void VertexDeclarationD3D9::update()
	{
		if (m_vertElements.size() != 0)
		{
			m_vertDecl = this->updateDeclaration();
		}
	}

	IDirect3DVertexDeclaration9* VertexDeclarationD3D9::updateDeclaration()
	{
		IDirect3DVertexDeclaration9* decl = 0;
		D3DVERTEXELEMENT9* elem = new D3DVERTEXELEMENT9[m_vertElements.size() + 1];

		int idX = 0;
		for (idX = 0, m_veIter = m_vertElements.begin(); m_veIter != m_vertElements.end(); ++m_veIter, ++idX)
		{
			VertexElement* vertElem = (*m_veIter);
			elem[idX].Stream = static_cast<WORD>(vertElem->getStreamNum());
			elem[idX].Offset = static_cast<WORD>(vertElem->getOffset());
			elem[idX].Method = D3D9Utility::GodVertMethodToD3DDECLMETHOD(vertElem->getMethod());
			elem[idX].Type = D3D9Utility::GodVertTypeToD3DDECLTYPE(vertElem->getDataType());
			elem[idX].Usage = D3D9Utility::GodVertUsageToD3DDECLUSAGE(vertElem->getUsage());
			elem[idX].UsageIndex = static_cast<BYTE>(vertElem->getUsageIndex());
		}

		elem[idX].Stream = 0xff;
		elem[idX].Offset = 0;
		elem[idX].Type = D3DDECLTYPE_UNUSED;
		elem[idX].Method = 0;
		elem[idX].Usage = 0;
		elem[idX].UsageIndex = 0;

		HRESULT hr = this->m_vertDevice->CreateVertexDeclaration(elem, &decl);

		if (FAILED(hr))
		{
			const char* err = DXGetErrorDescription(hr);

			MessageBox(NULL, err, err, MB_OK);
			return NULL;
		}

		return decl;
	}

	IDirect3DVertexDeclaration9* VertexDeclarationD3D9::getVertexDecl() const
	{
		return m_vertDecl;
	}
}