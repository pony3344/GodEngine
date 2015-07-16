#pragma once

#include "GodPrerequisites.h"

namespace GodEngine
{
	class Rectangle2D
	{
	protected:
		Real m_rLeft;
		Real m_rTop;
		Real m_rRight;
		Real m_rBottom;
	public:
		Rectangle2D();

		Rectangle2D(const Rectangle2D & rect);

		Rectangle2D(Real left, Real top, Real right, Real bottom);

		~Rectangle2D();

		void setDimensions(Real left,
			Real top,
			Real right,
			Real bottom);

		void setUpperLeftCorner(Real left, Real top);

		void setLowerRightCorner(Real right, Real bottom);

		void setLeft(Real Left);

		void setTop(Real top);

		void setRight(Real right);

		void setBottom(Real bottom);

		Real getLeft() const; 

		Real getTop() const; 

		Real getRight() const;

		Real getBottom() const;

		Real getWidth() const;

		Real getHeight() const;

		Real getArea() const;

		Real getPerimeter() const;
		
	};
}