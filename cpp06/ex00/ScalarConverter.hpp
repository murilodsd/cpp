#pragma once
#include <iostream>

#ifndef COLORS
# define COLORS
# define RESET "\033[0m"
# define BOLD "\033[1m"
# define BLACK "\033[30m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define WHITE "\033[37m"
#endif

class ScalarConverter
{
	private:
		// Default constructor
		ScalarConverter();

		// Copy constructor
		ScalarConverter(const ScalarConverter &other);

		// Copy assignment operator overload
		ScalarConverter &operator=(const ScalarConverter &other);

		// Destructor
		~ScalarConverter();
	public:

		//Others Methods
		static void convert(const std::string& cpp_literal);
};
