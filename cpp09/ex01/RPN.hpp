#pragma once
#include <iostream>
#include <stack>
#include <sstream>
#include <cstdlib>
#include <cstring>

class RPN
{
	private:
		static int check_expression(const char *expression);

	public:
		// Default constructor
		RPN();

		// Copy constructor
		RPN(const RPN &other);

		// Copy assignment operator overload
		RPN &operator=(const RPN &other);

		// Destructor
		~RPN();

		static int calculate(const char *expression);
};