#include "GodRectangle2D.h"

namespace GodEngine
{
	Rectangle2D::Rectangle2D()
		: m_rLeft(0.0),
		m_rTop(0.0),
		m_rRight(0.0),
		m_rBottom(0.0)
	{

	}

	Rectangle2D::Rectangle2D(const Rectangle2D & rect)
	{
		*this = rect;
	}
	Rectangle2D::Rectangle2D(Real left, Real top, Real right, Real bottom)
		: m_rLeft(left),
		m_rTop(top),
		m_rRight(right),
		m_rBottom(bottom)
	{

	}

	Rectangle2D::~Rectangle2D()
	{

	}

	void Rectangle2D::setDimensions(Real left,
		Real top,
		Real right,
		Real bottom)
	{
		this->setUpperLeftCorner(left, top);
		this->setLowerRightCorner(right, bottom);
	}

	void Rectangle2D::setUpperLeftCorner(Real left, Real top)
	{
		this->setLeft(left);
		this->setTop(top);
	}
	void Rectangle2D::setLowerRightCorner(Real right, Real bottom)
	{
		this->setRight(right);
		this->setBottom(m_rBottom);
	}

	void Rectangle2D::setLeft(Real Left)
	{
		m_rLeft = Left;
	}
	void Rectangle2D::setTop(Real top)
	{
		m_rTop = top; 
	}

	void Rectangle2D::setRight(Real right)
	{
		m_rRight = right;
	}

	void Rectangle2D::setBottom(Real bottom)
	{
		m_rBottom = bottom;
	}

	Real Rectangle2D::getLeft() const { return m_rLeft; }

	Real Rectangle2D::getTop() const { return m_rTop; }

	Real Rectangle2D::getRight() const { return m_rRight; }

	Real Rectangle2D::getBottom() const { return m_rBottom; }

	Real Rectangle2D::getWidth() const
	{
		return (m_rRight - m_rLeft);
	}
	Real Rectangle2D::getHeight() const
	{
		return (m_rBottom - m_rTop);
	}

	Real Rectangle2D::getArea() const
	{
		return this->getWidth() * this->getHeight();
	}

	Real Rectangle2D::getPerimeter() const
	{
		return 2.0f * (this->getWidth() + this->getHeight());
	}
}