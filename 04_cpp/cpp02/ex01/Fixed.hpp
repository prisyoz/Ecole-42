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
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif