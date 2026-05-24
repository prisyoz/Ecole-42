#include "Point.hpp"

// Formula: (P.x - B.x) * (A.y - B.y) - (A.x - B.x) * (P.y - B.y)
// AB X AP, BC X BP, CA X CP
// AB = (x2 - x1 . y2 - y1)
// All must be strictly > 0 (if vertices counter-clockwise)
// All strictly < 0 (if vertices are clockwise)
// If exactly 0, the point is on edge or vertex, return false

// Calculation of sides
static Fixed	calculate_side(Point const A, Point const B, Point const P)
{

	return ((P.getX() - B.getX()) * (A.getY() - B.getY()) - (A.getX() - B.getX()) * (P.getY() - B.getY()));
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	side1 = calculate_side(a, b, point);
	Fixed	side2 = calculate_side(b, c, point);
	Fixed	side3 = calculate_side(c, a, point);

	if ((side1 > 0 && side2 > 0 && side3 > 0) || (side1 < 0 && side2 < 0 && side3 < 0))
		return (true);
	else
		return (false);
}
