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
}

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

// ========== Comparison Operators Overload ==========

bool	Fixed::operator>(const Fixed &other) const
{
	return (this->_fixedPointNumber > other._fixedPointNumber);
};

bool	Fixed::operator<(const Fixed &other) const
{
	return (this->_fixedPointNumber < other._fixedPointNumber);
};

bool	Fixed::operator>=(const Fixed &other) const
{
	return (this->_fixedPointNumber >= other._fixedPointNumber);
};

bool	Fixed::operator<=(const Fixed &other) const
{
	return (this->_fixedPointNumber <= other._fixedPointNumber);
};

bool	Fixed::operator==(const Fixed &other) const
{
	return (this->_fixedPointNumber == other._fixedPointNumber);
};

bool	Fixed::operator!=(const Fixed &other) const
{
	return (this->_fixedPointNumber != other._fixedPointNumber);
};

// =========== Arithmetic operators Overload ===========

Fixed	Fixed::operator+(const Fixed &other) const
{
	return ( Fixed(this->toFloat() + other.toFloat()) );
}

Fixed	Fixed::operator-(const Fixed &other) const
{
	return ( Fixed(this->toFloat() - other.toFloat()) );
}

Fixed	Fixed::operator*(const Fixed &other) const
{
	return ( Fixed(this->toFloat() * other.toFloat()) );
}

Fixed	Fixed::operator/(const Fixed &other) const
{
	if (other._fixedPointNumber == 0)
	{
	    print_msg("Error: Division by zero", RED);
	    return Fixed(0); // Retorna um valor padrão ou lança uma exceção
	}
	return ( Fixed(this->toFloat() / other.toFloat()) );
}

// =========== Increment/decrement operators Overload ===========

Fixed	&Fixed::operator++()
{
	this->_fixedPointNumber++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed temp = *this;
	this->_fixedPointNumber++;
	return (temp);
}

Fixed	&Fixed::operator--()
{
	this->_fixedPointNumber--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed temp = *this;
	this->_fixedPointNumber--;
	return (temp);
}

// ================ Static Member Functions ================

Fixed	&Fixed::min(Fixed &fixedNum1, Fixed &fixedNum2)
{
	if (fixedNum1 < fixedNum2)
		return (fixedNum1);
	else
		return (fixedNum2);
}

const Fixed	&Fixed::min(const Fixed &fixedNum1, const Fixed &fixedNum2)
{
	if (fixedNum1 < fixedNum2)
		return (fixedNum1);
	else
		return (fixedNum2);
}

Fixed	&Fixed::max(Fixed &fixedNum1, Fixed &fixedNum2)
{
	if (fixedNum1 > fixedNum2)
		return (fixedNum1);
	else
		return (fixedNum2);
}

const Fixed	&Fixed::max(const Fixed &fixedNum1, const Fixed &fixedNum2)
{
	if (fixedNum1 > fixedNum2)
		return (fixedNum1);
	else
		return (fixedNum2);
}

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

// ================ Functions Members ==================

float	Fixed::toFloat( void ) const
{
	return (((float) _fixedPointNumber) / (1 << _fractionalBits));
}

int	Fixed::toInt( void ) const
{
	return (_fixedPointNumber >> _fractionalBits);
}