#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed 
{
	private:
		int					_fixed;
		static const int	_bits;
	
	public:
		Fixed();
		Fixed(const int nbr);
		Fixed(const float f);
		Fixed(const Fixed& original);
		Fixed& operator=(const Fixed& original);
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		// Comparison operators
		bool	operator>(const Fixed& other) const;
		bool	operator<(const Fixed& other) const;
		bool	operator>=(const Fixed& other) const;
		bool	operator<=(const Fixed& other) const;
		bool	operator==(const Fixed& other) const;
		bool	operator!=(const Fixed& other) const;

		// arithmetic operators
		Fixed	operator+(const Fixed& num) const;
		Fixed	operator-(const Fixed& num) const;
		Fixed	operator*(const Fixed& num) const;
		Fixed	operator/(const Fixed& num) const;

		// increment/decrement
		Fixed	&operator++(void);
		Fixed	&operator--(void);
		Fixed	operator++(int);
		Fixed	operator--(int);

		// min max
		static Fixed		&min(Fixed &n1, Fixed &n2);
		static const Fixed	&min(const Fixed &n1, const Fixed &n2);
		static Fixed		&max(Fixed &n1, Fixed &n2);
		static const Fixed	&max(const Fixed &n1, const Fixed &n2);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif