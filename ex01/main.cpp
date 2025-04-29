#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include "PhoneBook.hpp"
#include "utils.hpp"

void	print_instructions()
{
	std::cout << std::endl;
	std::cout << "Please enter the action you would like to perform:" << std::endl;
	std::cout << "-> ADD" << std::endl;
	std::cout << "-> SEARCH" << std::endl;
	std::cout << "-> EXIT" << std::endl;
	std::cout << std::endl;
}

int	main(int argc, char const *argv[])
{
	std::string	action;
	PhoneBook phonebook;

	while (true)
	{
		print_instructions();
		utils::getValidInput("Action: ", action);
		std::cout << std::endl;
		utils::toUpperCase(action);
		if (action == "ADD")
			phonebook.add_contact(phonebook);
		else if (action == "SEARCH")
			phonebook.search();
		else if (action == "EXIT")
			break ;
		else
			std::cout << RED << "Invalid option!" << std::endl << RESET;;
				
	}
	std::cout << BLUE << "See you soon!" << std::endl << RESET;
	return (EXIT_SUCCESS);
}