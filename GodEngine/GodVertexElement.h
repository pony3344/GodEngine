#pragma once

#include "GodPrerequisites.h"

namespace GodEngine
{
	class VertexElement
	{
	protected:
		uint16 m_ui16StreamNum;
		uint16 m_ui16Offset;
		GOD_VERTEX_DATA_TYPE m_vertType;
		GOD_VERTEX_METHOD    m_vertMethod;
		GOD_VERTEX_USAGE_TYPE m_vertUsage;
		uint16 m_uiUsageIndex;
	public:
		VertexElement();

		VertexElement(const VertexElement & cpy);

		VertexElement(uint16 streamNum,
			uint16 offset,
			GOD_VERTEX_DATA_TYPE vertData,
			GOD_VERTEX_METHOD method,
			GOD_VERTEX_USAGE_TYPE usage,
			uint16 usageIndex);

		void setElement(
			uint16 streamNum,
			uint16 offset,
			GOD_VERTEX_DATA_TYPE vertData,
			GOD_VERTEX_METHOD method,
			GOD_VERTEX_USAGE_TYPE usage,
			uint16 usageIndex);

		void setStreamNum(uint16 streamNum);

		uint16 getStreamNum() const;

		void setOffSet(uint16 offset);

		uint16 getOffset() const;

		void setDataType(GOD_VERTEX_DATA_TYPE dataType);

		GOD_VERTEX_DATA_TYPE getDataType() const;

		void setMethod(GOD_VERTEX_METHOD method);

		GOD_VERTEX_METHOD getMethod() const;

		void setUsage(GOD_VERTEX_USAGE_TYPE usage);

		GOD_VERTEX_USAGE_TYPE getUsage() const;
		
		void setUsageIndex(uint16 usageIndex);

		uint16 getUsageIndex() const;
	};
}