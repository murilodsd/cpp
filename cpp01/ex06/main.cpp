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

int main(int argc, const char *argv[])
{
	Harl harl;

	switch (argv[1])
	{
	case "DEBUG":
		{
			print_msg("[ DEBUG ]");
			harl.complain("DEBUG");
			print_msg("");
		}
	case "INFO":
		{
			print_msg("[ INFO ]");
			harl.complain("INFO");
			print_msg("");
		}
	case "WARNING":
		{
			print_msg("[ WARNING ]");
			harl.complain("WARNING");
			print_msg("");
		}
	case "ERROR":
	{
		print_msg("[ ERROR ]");
		harl.complain("ERROR");
		print_msg("");
	}
	default:
		print_msg("[ Probably complaining about insignificant problems ]", BLUE);
		break;
	}

	return (EXIT_SUCCESS);
}
