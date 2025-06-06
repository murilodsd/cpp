#pragma once
#include "Fixed.hpp"

class Point
{
private:
	const Fixed x;
	const Fixed y;
public:
	// Default constructor
	Point();
	Point(const float x, const float y);

	// Copy constructor
	Point(const Point &other);

	// Copy assignment operator overload
	Point &operator=(const Point &other);

	// Destructor
	~Point();

	// Getters
	const Fixed	&getX() const;
	const Fixed	&getY() const;

	//static
	static Fixed crossProductZ(Point const p1, Point const p2, Point const point_to_check) {
	return (p2.x - p1.x) * (point_to_check.y - p1.y) - \
		(p2.y - p1.y) * (point_to_check.x - p1.x);
	}
};