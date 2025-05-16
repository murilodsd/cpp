#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	// Calculate the orientation of the point relative to each edge of the triangle
	Fixed orient1 = Point::crossProductZ(a, b, point); // Orientation with respect to edge AB
	Fixed orient2 = Point::crossProductZ(b, c, point); // Orientation with respect to edge BC
	Fixed orient3 = Point::crossProductZ(c, a, point); // Orientation with respect to edge CA

	// Check if the point is on the same side of all edges (either all positive or all negative)
	bool all_positive = (orient1 > Fixed(0)) && (orient2 > Fixed(0)) && (orient3 > Fixed(0)); // All orientations are positive
	bool all_negative = (orient1 < Fixed(0)) && (orient2 < Fixed(0)) && (orient3 < Fixed(0)); // All orientations are negative
	
	// Return true if the point is inside the triangle (same side for all edges)
	return (all_positive || all_negative);
}