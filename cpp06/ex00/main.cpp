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
