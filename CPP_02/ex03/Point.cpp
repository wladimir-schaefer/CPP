#include "Point.hpp"

Point::Point(): _x(0), _y(0){}

Point::Point(float const x, float const y): _x(x), _y(y){}

Point::Point(const Point &other): _x(other._x), _y(other._y) {}

Point &Point::operator=(const Point &other) {
	(void)other;
	return *this;
}

Point::~Point(){}

Fixed Point::getX() const {
	return _x;
}

Fixed Point::getY() const {
	return _y;
}

Fixed sign(Point const &a, Point const &b, Point const &c)
{
	return (a.getX() - c.getX()) * (b.getY() - c.getY()) -
			(b.getX() - c.getX()) * (a.getY() - c.getY());
}