#include "GodVertexElement.h"

namespace GodEngine
{
	VertexElement::VertexElement()
	{
		this->setElement(0, 0, GVDT_FLOAT1, GVM_DEFAULT, GVUT_POSITION, 0);
	}

	VertexElement::VertexElement(const VertexElement & cpy)
	{
		*this = cpy;
	}
	VertexElement::VertexElement(uint16 streamNum,
		uint16 offset,
		GOD_VERTEX_DATA_TYPE vertData,
		GOD_VERTEX_METHOD method,
		GOD_VERTEX_USAGE_TYPE usage,
		uint16 usageIndex)
	{
		this->setElement(streamNum, offset, vertData, method, usage, usageIndex);
	}

	void VertexElement::setElement(
		uint16 streamNum,
		uint16 offset,
		GOD_VERTEX_DATA_TYPE vertData,
		GOD_VERTEX_METHOD method,
		GOD_VERTEX_USAGE_TYPE usage,
		uint16 usageIndex)
	{
		this->setStreamNum(streamNum);
		this->setOffSet(offset);
		this->setDataType(vertData);
		this->setMethod(method);
		this->setUsage(usage);
		this->setUsageIndex(usageIndex);
	}

	void VertexElement::setStreamNum(uint16 streamNum)
	{
		this->m_ui16StreamNum = streamNum;
	}
	uint16 VertexElement::getStreamNum() const
	{
		return m_ui16StreamNum;
	}

	void VertexElement::setOffSet(uint16 offset)
	{
		m_ui16Offset = offset;
	}
	uint16 VertexElement::getOffset() const
	{
		return m_ui16Offset;
	}
	void VertexElement::setDataType(GOD_VERTEX_DATA_TYPE dataType)
	{
		m_vertType = dataType;
	}

	GOD_VERTEX_DATA_TYPE VertexElement::getDataType() const
	{
		return m_vertType;
	}

	void VertexElement::setMethod(GOD_VERTEX_METHOD method)
	{
		m_vertMethod = method;
	}

	GOD_VERTEX_METHOD VertexElement::getMethod() const
	{
		return m_vertMethod;
	}

	void VertexElement::setUsage(GOD_VERTEX_USAGE_TYPE usage)
	{
		m_vertUsage = usage;
	}

	GOD_VERTEX_USAGE_TYPE VertexElement::getUsage() const
	{
		return m_vertUsage;
	}

	void VertexElement::setUsageIndex(uint16 usageIndex)
	{
		m_uiUsageIndex = usageIndex;
	}

	uint16 VertexElement::getUsageIndex() const
	{
		return m_uiUsageIndex;
	}
}