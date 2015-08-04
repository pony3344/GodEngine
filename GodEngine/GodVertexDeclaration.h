#pragma once

#include "GodPrerequisites.h"

namespace GodEngine
{
	typedef std::vector<VertexElement*> VertexElements;
	typedef VertexElements::iterator VertElemIter;
	class VertexDeclaration
	{
	protected:
		String m_sVertDeclName;
		VertexElements m_vertElements;
		VertElemIter m_veIter;
	public:
		VertexDeclaration();

		VertexDeclaration(String declName);

		VertexDeclaration(const VertexDeclaration & cpy);

		virtual ~VertexDeclaration(){}

		bool createVertexDeclaration(String vertName);

		void addElement(uint16 streamNum,
			uint16 offset,
			GOD_VERTEX_DATA_TYPE vertData,
			GOD_VERTEX_METHOD method,
			GOD_VERTEX_USAGE_TYPE usage,
			uint16 usageIndex);

		uint32 getNumElements() const;

		virtual void update();
	};
}