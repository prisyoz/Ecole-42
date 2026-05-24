#include "Fixed.hpp"

const int	Fixed::_bits = 8;

Fixed::Fixed() : _fixed(0)
{

}

Fixed::Fixed(const int nbr)
{
	this->_fixed = (nbr << _bits);
}

Fixed::Fixed(const float f)
{
	this->_fixed = roundf(f * (1 << _bits));
}

Fixed::Fixed(const Fixed& original)
{
	*this = original;
}

Fixed& Fixed::operator=(const Fixed& original)
{
	if (this != &original)
		this->_fixed = original.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{

}

int Fixed::getRawBits(void) const
{
	return (this->_fixed);
}

void Fixed::setRawBits(int const raw)
{
	this->_fixed = raw;
}

//convert fixed point to floating point
float Fixed::toFloat(void) const
{
	return ((float)this->_fixed / (1 << _bits));
}

// Fixed to int
int Fixed::toInt(void) const
{
	return (this->_fixed >> _bits);
}

// float point representation
std::ostream &operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}

// Comparison operators
bool	Fixed::operator>(const Fixed& other) const
{
	if (this->_fixed > other.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<(const Fixed& other) const
{
	if (this->_fixed < other.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator>=(const Fixed& other) const
{
	if (this->_fixed >= other.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<=(const Fixed& other) const
{
	if (this->_fixed <= other.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator==(const Fixed& other) const
{
	if (this->_fixed == other.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator!=(const Fixed& other) const
{
	if (this->_fixed != other.getRawBits())
		return (true);
	return (false);
}

// arithmetic operators
Fixed	Fixed::operator+(const Fixed& num) const
{
	return (Fixed(this->toFloat() + num.toFloat()));
}

Fixed	Fixed::operator-(const Fixed& num) const
{
	return (Fixed(this->toFloat() - num.toFloat()));
}

Fixed	Fixed::operator*(const Fixed& num) const
{
	return (Fixed(this->toFloat() * num.toFloat()));
}

Fixed	Fixed::operator/(const Fixed& num) const
{
	return (Fixed(this->toFloat() / num.toFloat()));
}

// Pre increment
Fixed& Fixed::operator++(void)
{
	++this->_fixed;
	return (*this);
}

Fixed& Fixed::operator--(void)
{
	--this->_fixed;
	return (*this);
}

// Post increment
Fixed Fixed::operator++(int)
{
	Fixed	saved(*this);

	this->_fixed++;
	return (saved);
}

Fixed Fixed::operator--(int)
{
	Fixed	saved(*this);

	this->_fixed--;
	return (saved);
}

// min max
Fixed& Fixed::min(Fixed &n1, Fixed &n2)
{
	if (n1 > n2 )
		return (n2);
	return (n1);
}

const Fixed& Fixed::min(const Fixed &n1, const Fixed &n2)
{
	if (n1 > n2)
		return (n2);
	return (n1);
}

Fixed&	Fixed::max(Fixed &n1, Fixed &n2)
{
	if (n1 > n2)
		return (n1);
	return (n2);
}

const Fixed& Fixed::max(const Fixed &n1, const Fixed &n2)
{
	if (n1 > n2)
		return (n1);
	return (n2);
}
