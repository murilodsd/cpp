#include <iostream>
#include <cstdlib>
#include "Harl.hpp"

#define RESET "\033[0m"
#define BOLD "\033[1m"
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define WHITESPACE_CHARS " \t\n\r\f\v"

void	print_msg(const std::string& str, const std::string& color = WHITE)
{
	std::cout << color << str << std::endl << RESET;
}

int main()
{
	Harl harl;

	print_msg("Harl is about to complain at different levels:\n", CYAN);

	print_msg("[DEBUG]", MAGENTA);
	harl.complain("DEBUG");
	print_msg(""); //line break

	print_msg("[INFO]", MAGENTA);
	harl.complain("INFO");
	print_msg(""); //line break

	print_msg("[WARNING]", MAGENTA);
	harl.complain("WARNING");
	print_msg(""); //line break

	print_msg("[ERROR]", MAGENTA);
	harl.complain("ERROR");
	print_msg(""); //line break

	print_msg("All complaints have been processed.", CYAN);

	return (EXIT_SUCCESS);
}
