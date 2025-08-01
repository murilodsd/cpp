#include "ScalarConverter.hpp"
#include <cstdlib>

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		std::cout << "Usage: ./convert <string>" << std::endl;
		return EXIT_FAILURE;
	}
	ScalarConverter::convert(argv[1]);
	return 0;
}

/* int main()
{
	// Basic numeric values
	std::cout << "\nTest 1: Converting \"42\"" << std::endl;
	ScalarConverter::convert("42");
	std::cout << "----------------------------------------" << std::endl;
	
	std::cout << "Test 2: Converting \"-42\"" << std::endl;
	ScalarConverter::convert("-42");
	std::cout << "----------------------------------------" << std::endl;
	
	std::cout << "Test 3: Converting \"0\"" << std::endl;
	ScalarConverter::convert("0");
	std::cout << "----------------------------------------" << std::endl;
	
	// Float values
	std::cout << "Test 4: Converting \"42.0f\"" << std::endl;
	ScalarConverter::convert("42.0f");
	std::cout << "----------------------------------------" << std::endl;
	
	std::cout << "Test 5: Converting \"-42.42f\"" << std::endl;
	ScalarConverter::convert("-42.42f");
	std::cout << "----------------------------------------" << std::endl;
	
	std::cout << "Test 6: Converting \"0.0f\"" << std::endl;
	ScalarConverter::convert("0.0f");
	std::cout << "----------------------------------------" << std::endl;
	
	// Double values
	std::cout << "Test 7: Converting \"42.0\"" << std::endl;
	ScalarConverter::convert("42.0");
	std::cout << "----------------------------------------" << std::endl;
	
	std::cout << "Test 8: Converting \"-42.42\"" << std::endl;
	ScalarConverter::convert("-42.42");
	std::cout << "----------------------------------------" << std::endl;
	
	// Special float values
	std::cout << "Test 9: Converting \"nanf\"" << std::endl;
	ScalarConverter::convert("nanf");
	std::cout << "----------------------------------------" << std::endl;
	
	std::cout << "Test 10: Converting \"+inff\"" << std::endl;
	ScalarConverter::convert("+inff");
	std::cout << "----------------------------------------" << std::endl;
	
	std::cout << "Test 11: Converting \"-inff\"" << std::endl;
	ScalarConverter::convert("-inff");
	std::cout << "----------------------------------------" << std::endl;
	
	// Special double values
	std::cout << "Test 12: Converting \"nan\"" << std::endl;
	ScalarConverter::convert("nan");
	std::cout << "----------------------------------------" << std::endl;
	
	std::cout << "Test 13: Converting \"+inf\"" << std::endl;
	ScalarConverter::convert("+inf");
	std::cout << "----------------------------------------" << std::endl;
	
	std::cout << "Test 14: Converting \"-inf\"" << std::endl;
	ScalarConverter::convert("-inf");
	std::cout << "----------------------------------------" << std::endl;
	
	// Edge cases - Integer limits
	std::cout << "Test 15: Converting \"2147483647\"" << std::endl;
	ScalarConverter::convert("2147483647");
	std::cout << "----------------------------------------" << std::endl;
	
	std::cout << "Test 16: Converting \"-2147483648\"" << std::endl;
	ScalarConverter::convert("-2147483648");
	std::cout << "----------------------------------------" << std::endl;
	
	std::cout << "Test 17: Converting \"2147483648\"" << std::endl;
	ScalarConverter::convert("2147483648");
	std::cout << "----------------------------------------" << std::endl;
	
	// Edge cases - Character limits
	std::cout << "Test 18: Converting \"127\"" << std::endl;
	ScalarConverter::convert("127");
	std::cout << "----------------------------------------" << std::endl;
	
	std::cout << "Test 19: Converting \"128\"" << std::endl;
	ScalarConverter::convert("128");
	std::cout << "----------------------------------------" << std::endl;
	
	std::cout << "Test 20: Converting \"255\"" << std::endl;
	ScalarConverter::convert("255");
	std::cout << "----------------------------------------" << std::endl;
	
	std::cout << "Test 21: Converting \"256\"" << std::endl;
	ScalarConverter::convert("256");
	std::cout << "----------------------------------------" << std::endl;
	
	// Edge cases - Float precision
	std::cout << "Test 22: Converting \"3.4028235e+38f\"" << std::endl;
	ScalarConverter::convert("3.4028235e+38f");
	std::cout << "----------------------------------------" << std::endl;
	
	std::cout << "Test 23: Converting \"1.175494e-38f\"" << std::endl;
	ScalarConverter::convert("1.175494e-38f");
	std::cout << "----------------------------------------" << std::endl;
	
	// Invalid cases
	std::cout << "Test 24: Converting \"abc\"" << std::endl;
	ScalarConverter::convert("abc");
	std::cout << "----------------------------------------" << std::endl;
	
	std::cout << "Test 25: Converting \"\"" << std::endl;
	ScalarConverter::convert("");
	std::cout << "----------------------------------------" << std::endl;
	
	std::cout << "Test 26: Converting \"42.f\"" << std::endl;
	ScalarConverter::convert("42.f");
	std::cout << "----------------------------------------" << std::endl;
	
	std::cout << "Test 27: Converting \"42ff\"" << std::endl;
	ScalarConverter::convert("42ff");
	std::cout << "----------------------------------------" << std::endl;
	return 0;
}
 */