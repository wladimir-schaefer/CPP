#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point){

	Fixed d1 = sign(point, a, b);
	Fixed d2 = sign(point, b, c);
	Fixed d3 = sign(point, c, a);

	bool has_neg = (d1 < Fixed(0)) || (d2 < Fixed(0)) || (d3 < Fixed(0));
	bool has_pos = (d1 > Fixed(0)) || (d2 > Fixed(0)) || (d3 > Fixed(0));

	if (d1 == Fixed(0) || d2 == Fixed(0) || d3 == Fixed(0))
		return false;

	return !(has_neg && has_pos);
}
