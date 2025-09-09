#include <iostream>
#include "RPN.hpp"

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

int main(int argc, char const *argv[])
{
	if (argc != 2) {
		std::cerr << RED  << "Error: Usage: ./RPN <expression>" << RESET << std::endl;
		return EXIT_FAILURE;
	}
	try {
		std::cout << RPN::calculate(argv[1]) << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << "Error: " << e.what() << '\n';
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
