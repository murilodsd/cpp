#include "convert_functions.hpp"
#include <iostream>
#include <iomanip>
#include <climits>

void printImpossibleCases()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

void convertChar(char c)
{
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void convertInt(const std::string& cpp_literal)
{
	int	num;
	std::istringstream iss(cpp_literal);
	iss >> num;

	if (iss.fail())
		printImpossibleCases();
	else
	{
		if (num >= 0 && num <= 255 && isprint(num))
			std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << num << std::endl;
		// Large int values ( > 2^24) may not be represented exactly as float due to precision limitations of the type.
		std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(num) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(num) << std::endl;
	}
}

void convertFloat(const std::string& cpp_literal)
{
	std::istringstream iss(cpp_literal);
	float	float_num;
	iss >> float_num;

	if (iss.fail())
		printImpossibleCases();
	else
	{
		if (static_cast<int>(float_num) >= 0 \
			&& static_cast<int>(float_num) <= 127 \
			&& isprint(static_cast<int>(float_num)))
			std::cout << "char: '" << static_cast<char>(float_num) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		if (float_num <= INT_MAX && float_num >= INT_MIN)
			std::cout << "int: " << static_cast<int>(float_num) << std::endl;
		else
			std::cout << "int: impossible" << std::endl;
		// Large int values ( > 2^24) may not be represented exactly as float due to precision limitations of the type.
		std::cout << std::fixed << std::setprecision(1) << "float: " << float_num << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(float_num) << std::endl;
	}
}

void convertDouble(const std::string& cpp_literal)
{
	std::istringstream iss(cpp_literal);
	double	double_num;
	iss >> double_num;

	if (iss.fail())
		printImpossibleCases();
	else
	{
		double intpart;
		if (static_cast<int>(double_num) >= 0 \
			&& static_cast<int>(double_num) <= 127 \
			&& isprint(static_cast<int>(double_num)))
			std::cout << "char: '" << static_cast<char>(double_num) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		if (double_num <= INT_MAX && double_num >= INT_MIN)
			std::cout << "int: " << static_cast<int>(double_num) << std::endl;
		else
			std::cout << "int: impossible" << std::endl;
		// Large int values ( > 2^24) may not be represented exactly as float due to precision limitations of the type.
		std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(double_num) << "f" << std::endl;
		std::cout << "double: " << double_num << std::endl;
	}
}