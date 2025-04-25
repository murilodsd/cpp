#include <iostream>
#include <string>
#include <cctype>
#include <PhoneBook.hpp>

void	toUpperCase(std::string &str)
{
	size_t i = 0;
	while (i < str.length())
	{
		str[i] = std::toupper(str[i]);
		i++;
	}
}

void	print_instructions()
{
	std::cout << std::endl;
	std::cout << "Please enter the action you would like to perform:" << std::endl;
	std::cout << "-> ADD" << std::endl;
	std::cout << "-> SEARCH" << std::endl;
	std::cout << "-> EXIT" << std::endl;
	std::cout << std::endl;
	std::cout << "Action: ";
}

int	main(int argc, char const *argv[])
{
	bool	exit;
	std::string	action;
	PhoneBook phonebook;

	exit = false;
	while (exit == false)
	{
		print_instructions();
		std::cin >> action;
		std::cout << std::endl;
		toUpperCase(action);
		if (action == "ADD")
			phonebook.add_contact(phonebook);
		else if (action == "SEARCH")
			phonebook.search();
		else if (action == "EXIT")
			exit = true;
		else
			std::cout << RED << "Invalid option!" << std::endl << RESET;;
				
	}
	std::cout << BLUE << "See you soon!" << std::endl << RESET;
	return (EXIT_SUCCESS);
}