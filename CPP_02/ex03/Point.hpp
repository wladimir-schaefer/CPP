#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point{
private:
	const Fixed _x;
	const Fixed _y;

public:
	Point();
	Point(float const x, float const y);
	Point(const Point &other);
	Point &operator=(const Point &other);
	~Point();
	Fixed getX() const;
	Fixed getY() const;
};

Fixed sign(Point const &a, Point const &b, Point const &c);

#endif