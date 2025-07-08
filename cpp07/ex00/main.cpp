/*
Subject: Function Templates

Objective: This is an introductory exercise to the concept of function templates.
The goal is for you to learn the basic syntax for creating generic functions.
You will need to implement three simple template functions:

- swap: A function that swaps the values of two variables of any type.
- min: A function that returns the smaller of two values of any type.
- max: A function that returns the larger of two values of any type.

The challenge is to ensure that these functions work correctly with primitive types
(such as int, float, char) and with more complex types, as long as the necessary operators
(such as <, >, and the copy constructor) are defined for those types.
This is the first step towards understanding how to write code that avoids duplication.
*/
#include "utils_templates.hpp"
#include <iostream>



int main( void )
{
	std::cout << "=== Integer swap and min/max ===" << std::endl;
	int a = 2;
	int b = 3;
	std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
	::swap( a, b );
	std::cout << "After swap: a = " << a << ", b = " << b << std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::cout << "\n=== String swap and min/max ===" << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	std::cout << "Before swap: c = " << c << ", d = " << d << std::endl;
	::swap(c, d);
	std::cout << "After swap: c = " << c << ", d = " << d << std::endl;
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	return 0;
}