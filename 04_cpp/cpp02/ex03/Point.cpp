#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{

}

Point::Point(const float x, const float y) : _x(x), _y(y)
{

}

Point::Point(const Point& original) : _x(original._x), _y(original._y)
{

}

Point& Point::operator=(const Point& original)
{
	(void)original;
	return (*this);
}

Point::~Point()
{

}

Fixed	Point::getX(void) const
{
	return (this->_x);
}

Fixed	Point::getY(void) const
{
	return (this->_y);
}