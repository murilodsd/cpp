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

e_data_type checkDataType(const std::string& cpp_literal)
{
	if (cpp_literal.length() == 1 && std::isalpha(cpp_literal.at(0)))
		return CHAR;
	
	const char* ptr_cpp_literal = cpp_literal.c_str();
	if (cpp_literal.at(0) == '+' || cpp_literal.at(0) == '-')
		ptr_cpp_literal++;

	if (utils::is_str_number(cpp_literal, ""))
}



void ScalarConverter::convert(const std::string& cpp_literal)
{
	if (cpp_literal.length() == 1)
	{
		if (std::isalpha(cpp_literal.at(0)))
			convertChar(cpp_literal.at(0));
		else if (cpp_literal.at(0) == '0')
			convertInt(std::atoi(cpp_literal.c_str()));
	} 
	else if (cpp_literal.length() == 1 and std::isalpha(cpp_literal.at(0)))
		convertInt(std::atoi(cpp_literal.c_str()));
}