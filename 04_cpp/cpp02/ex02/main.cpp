#include "Fixed.hpp"

#include <iostream>

int main( void ) 
{
	std::cout << "=== Subject test ===\n";
	{
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		
		std::cout << Fixed::max( a, b ) << std::endl;
	}

	std::cout << "\n=== Operator test ===\n";
	{
		Fixed const c(Fixed(3.12345f) * Fixed(5));
		Fixed const d(Fixed(3.1f) * Fixed(5));
		Fixed e(5.5f);
		Fixed f(3.9f);
		Fixed g(3.9f);

		std::cout << "c: " << c << std::endl;
		std::cout << "d: " << d << std::endl;
		std::cout << "e: " << e << std::endl;
		std::cout << "f: " << f << std::endl;
		std::cout << "g: " << g << std::endl;
		std::cout << "\n";
		
		// operator
		if (c >= d)
			std::cout << "c is greater than d" << std::endl;
		if (c <= d)
			std::cout << "c is smaller than d" << std::endl;

		if (e > d)
			std::cout << "e > d" << std::endl;
		if (d < e)
			std::cout << "d < e" << std::endl;

		// assignment operator
		std::cout << "\nassignment operator e = d\n";
		e = d;

		std::cout << "d: " << d << std::endl;
		std::cout << "e: " << e << std::endl;
		std::cout << "\n";

		if (d == e)
			std::cout << "e is equal to d" << std::endl;
		if (c != e)
			std::cout << "c is not equal to e" << std::endl;

		if (f >= g)
    		std::cout << "f >= g when equal" << std::endl;
		if (f <= g)
   			 std::cout << "f <= g when equal" << std::endl;
	}

	std::cout << "\n=== Arithmetic operators ===\n";
	{
		Fixed a;
		Fixed const b( Fixed( -5.05f ) * Fixed( 2 ) );
		Fixed c(0);
		
		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << std::endl;
		std::cout << "c: " << c << std::endl;

		std::cout << "a + b: " << a + b << std::endl;
		std::cout << "a - b: " << a - b << std::endl;

		a.setRawBits(12);
		std::cout << "a set Raw Bits: " << a << std::endl;
		a = 12;
		std::cout << "a: " << a << std::endl;

		std::cout << "a * b: " << a * b << std::endl;
		std::cout << "a / b: " << a / b << std::endl;

		std::cout << "Zero division\n";
		std::cout << "a / c: " << a / c << std::endl;
	}

	std::cout << "\n=== Increment Operators ===\n";
	{
		Fixed a = 1;

		std::cout << "a: " << a << " | Raw: " << a.getRawBits() << std::endl;
		std::cout << "a++: " << a++ << " | Raw: " << a.getRawBits() << std::endl;
		std::cout << "a: " << a << " | Raw: " << a.getRawBits() << std::endl;
		std::cout << "++a: " << ++a << " | Raw: " << a.getRawBits() << std::endl;
		std::cout << "a: " << a << " | Raw: " << a.getRawBits() << std::endl;
		std::cout << "a++: " << a++ << " | Raw: " << a.getRawBits() << std::endl;
		std::cout << "a: " << a << " | Raw: " << a.getRawBits() << std::endl;

		std::cout << "Decrement\n";
		std::cout << "a: " << a << " | Raw: " << a.getRawBits() << std::endl;
		std::cout << "a--: " << a-- << " | Raw: " << a.getRawBits() << std::endl;
		std::cout << "a: " << a << " | Raw: " << a.getRawBits() << std::endl;
		std::cout << "--a: " << --a << " | Raw: " << a.getRawBits() << std::endl;
		std::cout << "a: " << a << " | Raw: " << a.getRawBits() << std::endl;
		std::cout << "a--: " << a-- << " | Raw: " << a.getRawBits() << std::endl;
		std::cout << "a: " << a << " | Raw: " << a.getRawBits() << std::endl;
	}

	std::cout << "\n=== Min Max test ===\n";
	{
		Fixed const c(Fixed(3.12345f) * Fixed(5));
		Fixed const d(Fixed(3.1f) * Fixed(5));

		std::cout << Fixed::max(c, d) << std::endl;
		std::cout << Fixed::min(c, d) << std::endl;

		Fixed x(10);
		Fixed y(20);

		std::cout << "x is now: " << x << std::endl;
		std::cout << "y is now: " << y << std::endl;
		std::cout << "Min: " << Fixed::min(x, y) << std::endl;
		std::cout << "Max: " << Fixed::max(x, y) << std::endl;

		Fixed::max(x, y).setRawBits(0);

		std::cout << "x is now: " << x << std::endl;
		std::cout << "y is now: " << y << std::endl;

	}
	return 0;
}