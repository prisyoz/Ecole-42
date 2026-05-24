#include "Point.hpp"

static void	test_run(Point const a, Point const b, Point const c, Point const p, std::string name)
{
	std::cout << name << ": ";
	if (bsp(a, b, c, p) == true)
		std::cout << "True" << std::endl;
	else
		std::cout << "False" << std::endl;
}

int main( void ) 
{
	Point a(0, 0);
	Point b(10, 0);
	Point c(0, 10);

	test_run(a, b, c, Point(2, 2), "Point Inside"); //true
	test_run(a, b, c, Point(15, 15), "Point Outside"); // false
	test_run(a, b, c, Point(100, 100), "Far outside"); // false
	test_run(a, b, c, Point(5, 0), "Point on Edge"); // false
	test_run(a, b, c, Point(0, 0), "Point on Vertex"); // false
	test_run(a, b, c, Point(0.1f, 0.1f), "Barely inside"); // true
	test_run(a, b, c, Point(5.1f, 5.1f), "Barely outside"); // false
	test_run(a, b, c, Point(0, 0.1), "On the edge"); // false
	test_run(a, b, c, Point(10, 0), "Vertex B"); // false
	test_run(a, b, c, Point(0, 10), "Vertex C"); // false
	test_run(a, b, c, Point(5, 5), "On hypotenuse"); // false
	test_run(a, b, c, Point(4.9f, 5.0f), "Near hypotenuse inside"); // true
	test_run(a, b, c, Point(5.1f, 4.9f), "Near hypotenuse outside"); // false

	Point x(0, 0);
	Point y(1, 0);
	Point z(0, 1);
	test_run(x, y, z, Point(0.1, 0.1), "Fractional"); // true

	Point p(-5, -5);
	Point q(-10, 0);
	Point r(-5, -10);
	test_run(p, q, r, Point(-6, -6), "Negative triangle inside"); // true
	test_run(p, q, r, Point(0, 0), "Negative triangle outside"); // false

	Point dup1(0,0);
	Point dup2(0,0);
	Point dup3(5,5);
	test_run(dup1, dup2, dup3, Point(1,1), "Duplicate vertices"); // false

	Point t1(100,100);
	Point t2(110,100);
	Point t3(100,110);
	test_run(t1, t2, t3, Point(102,102), "Inside"); // true
	
    return (0);
}
