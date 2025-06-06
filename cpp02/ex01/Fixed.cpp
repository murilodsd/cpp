#include <string>
#include <iostream>
#include "Fixed.hpp"
#include <cmath>

// ================= Auxiliar Functions ================

void	print_msg(const std::string& str, const std::string& color = WHITE)
{
	std::cout << color << str << std::endl << RESET;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return (out);
};

// ==================== Constructor ====================
Fixed::Fixed()
:
_fixedPointNumber(0)
{
	print_msg("Default constructor called");
};

Fixed::Fixed(const int number)
{
	print_msg("Int constructor called");
	_fixedPointNumber = number << _fractionalBits;
};

Fixed::Fixed(const float number)
{
	print_msg("Float constructor called");
	// Bitwise shifting cannot be directly used with float, so we multiply by the equivalent power of 2
	// 2 ^ _fractionalBits = (1 << _fractionalBits)
	_fixedPointNumber = (int) roundf((number * (1 << _fractionalBits)));
};

// ================= Copy Constructor ==================
Fixed::Fixed(const Fixed &other)
{
	print_msg("Copy constructor called");
	*this = other;
};

// ========== Copy Assignment Operator Overload ==========
Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
	{
		print_msg("Copy assignment operator called");
		this->_fixedPointNumber = other.getRawBits();
	}
	return *this;
};

// ==================== Destructor =====================
Fixed::~Fixed()
{
	print_msg("Destructor called");
};

// ===================== Setters =======================

void	Fixed::setRawBits(const int &raw)
{
	print_msg("setRawBits member function called");
	this->_fixedPointNumber = raw;
};

// ===================== Getters =======================

int	Fixed::getRawBits(void) const
{
	print_msg("getRawBits member function called");
	return (this->_fixedPointNumber);
};

// ================ Functions Members ==================

float	Fixed::toFloat( void ) const
{
	return (((float) _fixedPointNumber) / (1 << _fractionalBits));
};

int	Fixed::toInt( void ) const
{
	return (_fixedPointNumber >> _fractionalBits);
};