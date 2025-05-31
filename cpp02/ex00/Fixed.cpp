#include <string>
#include <iostream>
#include "Fixed.hpp"

// ================= Auxiliar Functions ================

void	print_msg(const std::string& str, const std::string& color = WHITE)
{
	std::cout << color << str << std::endl << RESET;
};

// ==================== Constructor ====================
Fixed::Fixed()
:
_fixedPointNumber(0)
{
	print_msg("Default constructor called");
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

// ================= Copy Constructor ==================
Fixed::Fixed(const Fixed &other)
{
	print_msg("Copy constructor called");
	*this = other;
};

// ==================== Destructor =====================
Fixed::~Fixed()
{
	print_msg("Destructor called");
};

// ===================== Setters =======================

void	Fixed::setRawBits(int const raw)
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