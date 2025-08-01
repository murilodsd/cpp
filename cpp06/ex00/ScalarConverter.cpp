#include "ScalarConverter.hpp"
#include "utils.hpp"
#include "convert_functions.hpp"
#include <string>
#include <iostream>
#include <sstream>
#include <cmath>

enum e_data_type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	SPECIAL_CASE,
	NONE
};

// ==================== Constructors ====================
ScalarConverter::ScalarConverter()
{
}

// ================= Copy Constructor ==================
ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
}

// ========== Copy Assignment Operator Overload ==========
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return *this;
}

// ==================== Destructor =====================
ScalarConverter::~ScalarConverter()
{
}
// ================= Auxiliar Functions =================

void printSpecialCase(const std::string& cpp_literal)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (cpp_literal == "nanf" || cpp_literal == "nan")
	{
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else
	{
		std::cout << "float: " << cpp_literal[0] << "inff" << std::endl;
		std::cout << "double: " << cpp_literal[0] << "inf" << std::endl;
	}
}

bool	isSpecialCase(const std::string& cpp_literal)
{
	std::string specialCases[6] = { "-inff", "+inff", "nanf", "-inf", "+inf", "nan"};

	for (int i = 0; i < 6; i++)
	{
		if (cpp_literal == specialCases[i])
			return true;
	}
	return (false);
}


// ================== Member Functions ==================

e_data_type checkDataType(const std::string& cpp_literal)
{
	if (cpp_literal.empty())
		return (NONE);
	if (isSpecialCase(cpp_literal))
		return (SPECIAL_CASE);
	if (cpp_literal.length() == 1 && !isdigit(cpp_literal.at(0)))
		return (CHAR);
	if (utils::is_str_number(cpp_literal, ""))
		return (INT);
	const char* ptr_cpp_literal = cpp_literal.c_str();
	if (cpp_literal.at(0) == '+' || cpp_literal.at(0) == '-')
		ptr_cpp_literal++;
	while (isdigit(*ptr_cpp_literal))
		ptr_cpp_literal++;
	if (*ptr_cpp_literal == '.')
	{
		ptr_cpp_literal++;
		while (isdigit(*ptr_cpp_literal))
			ptr_cpp_literal++;
		if (*ptr_cpp_literal == 'f' && ptr_cpp_literal[1] == '\0')
			return (FLOAT);
		else if (*ptr_cpp_literal == '\0')
			return (DOUBLE);
	}
	return (NONE);
}

void ScalarConverter::convert(const std::string& cpp_literal)
{
	e_data_type dataType = checkDataType(cpp_literal);
	
	switch (dataType)
	{
		case CHAR:
			convertChar(cpp_literal.at(0));
			break;
		case INT:
			convertInt(cpp_literal);
			break;
		case FLOAT:
			convertFloat(cpp_literal);
			break;
		case DOUBLE:
			convertDouble(cpp_literal);
			break;
		case SPECIAL_CASE:
			printSpecialCase(cpp_literal);
			break;
		case NONE:
			printImpossibleCases();
			break;
	}
}
