#include "Point.hpp"
#include "Fixed.hpp"
#include <iostream>

// ==================== Constructor ====================
Point::Point()
:
x(0),
y(0)
{
};

Point::Point(const float x, const float y)
:
x(x),
y(y)
{
};

// ================= Copy Constructor ==================
Point::Point(const Point &other)
:
x(other.x),
y(other.y)
{
};

// ========== Copy Assignment Operator Overload ==========
Point &Point::operator=(const Point &other)
{
	(void)other;
	std::cout << RED << "It is not possible to assign a value to an immutable variable." << RESET << std::endl;
	return *this;
};

// ==================== Destructor =====================
Point::~Point()
{
};

// =============== Setters and Getters ===============

const Fixed	&Point::getX() const
{
	return (x);
};

const Fixed	&Point::getY() const
{
	return (y);
};