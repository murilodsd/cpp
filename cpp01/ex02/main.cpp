#include <string>
#include <iostream>
#include <cstdlib>

// Define colors for terminal output
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

int	main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string* stringPTR = &str;
	std::string& stringREF = str;
	
	std::cout << std::endl;
	
	std::cout << GREEN << "=== Memory Addresses ===" << RESET << std::endl;
	std::cout << CYAN << "The memory address of the string variable: " << RESET << &str << std::endl;
	std::cout << CYAN << "The memory address held by stringPTR: " << RESET << stringPTR << std::endl;
	std::cout << CYAN << "The memory address held by stringREF: " << RESET << &stringREF << std::endl;

	std::cout << std::endl;

	std::cout << GREEN << "=== Values ===" << RESET << std::endl;
	std::cout << CYAN << "The value of the string variable: " << RESET << str << std::endl;
	std::cout << CYAN << "The value pointed to by stringPTR: " << RESET << *stringPTR << std::endl;
	std::cout << CYAN << "The value pointed to by stringREF: " << RESET << stringREF << std::endl;

	return (EXIT_SUCCESS);
}
