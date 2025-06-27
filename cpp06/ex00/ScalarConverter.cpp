#include "ScalarConverter.hpp"
#include "utils.hpp"
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

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
void convertChar(char c)
{
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void convertInt(char c)
{
	std::cout << "char: '" << (std::isprint(c) ?  std::string (1, c) : "Non displayable") << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void convertSpecialCase(const std::string& cpp_literal)
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


// ================== Member Functions ==================

enum e_data_type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	SPECIAL_CASE,
	NONE
};

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

e_data_type checkDataType(const std::string& cpp_literal)
{
	if (isSpecialCase(cpp_literal))
		return (SPECIAL_CASE);
	if (cpp_literal.length() == 1 && std::isalpha(cpp_literal.at(0)))
		return (CHAR);
	if (utils::is_str_number(cpp_literal, ""))
		return (INT);
	const char* ptr_cpp_literal = cpp_literal.c_str();
	if (cpp_literal.at(0) == '+' || cpp_literal.at(0) == '-')
		ptr_cpp_literal++;
	if (std::isdigit(*ptr_cpp_literal))
	{
		while (std::isdigit(*ptr_cpp_literal))
			ptr_cpp_literal++;
		if (*ptr_cpp_literal == '.' && std::isdigit(ptr_cpp_literal[1]))
		{
			ptr_cpp_literal++;
			while (std::isdigit(*ptr_cpp_literal))
				ptr_cpp_literal++;
			if (*ptr_cpp_literal == 'f' && ptr_cpp_literal[1] == '\0')
				return (FLOAT);
			else if (*ptr_cpp_literal == '\0')
				return (DOUBLE);
		}
	}
	return (NONE);
}



void ScalarConverter::convert(const std::string& cpp_literal)
{
	e_data_type dataType = checkDataType(cpp_literal);
	
	switch (dataType)
	{
		case CHAR:
			std::cout << "Data type found: CHAR" << std::endl;
			break;
		case INT:
			std::cout << "Data type found: INT" << std::endl;
			break;
		case FLOAT:
			std::cout << "Data type found: FLOAT" << std::endl;
			break;
		case DOUBLE:
			std::cout << "Data type found: DOUBLE" << std::endl;
			break;
		case SPECIAL_CASE:
			std::cout << "Data type found: SPECIAL_CASE" << std::endl;
			break;
		case NONE:
			std::cout << "Data type found: NONE" << std::endl;
			break;
	}
	
/* 	if (cpp_literal.length() == 1)
	{
		if (std::isalpha(cpp_literal.at(0)))
			convertChar(cpp_literal.at(0));
		else if (cpp_literal.at(0) == '0')
			convertInt(std::atoi(cpp_literal.c_str()));
	} 
	else if (cpp_literal.length() == 1 and std::isalpha(cpp_literal.at(0)))
		convertInt(std::atoi(cpp_literal.c_str())); */
}