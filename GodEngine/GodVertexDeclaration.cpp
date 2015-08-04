#include "GodVertexDeclaration.h"
#include "GodVertexElement.h"

namespace GodEngine
{
	VertexDeclaration::VertexDeclaration()
	{
		m_sVertDeclName = "_default_Decl";
	}

	VertexDeclaration::VertexDeclaration(const VertexDeclaration & cpy)
	{
		*this = cpy;
	}

	VertexDeclaration::VertexDeclaration(String declName)
	{
		m_sVertDeclName = declName;
	}

	bool VertexDeclaration::createVertexDeclaration(String vertName)
	{
		m_sVertDeclName = vertName;
		return true;
	}

	void VertexDeclaration::addElement(uint16 streamNum, uint16 offset, GOD_VERTEX_DATA_TYPE vertData, GOD_VERTEX_METHOD method, GOD_VERTEX_USAGE_TYPE usage, uint16 usageIndex)
	{
		VertexElement* elem = new VertexElement(streamNum, offset, vertData, method, usage, usageIndex);
		this->m_vertElements.push_back(elem);
	}

	uint32 VertexDeclaration::getNumElements() const
	{
		return (uint32)(m_vertElements.size());
	}

	void VertexDeclaration::update()
	{

	}
}