#include <iostream>
#include <cstdlib>
#include "Harl.hpp"

int main(int argc, const char *argv[])
{
	(void) argc;
	if (argc != 2)
	{
		std::cerr << RED << "Error: Invalid number of arguments.\n"
			<< "Usage: ./program <complain_level>" << RESET << std::endl;
		std::exit(EXIT_FAILURE);
	}

	Harl harlInstance;
	harlInstance.complain(argv[1]);

	return (EXIT_SUCCESS);
}
