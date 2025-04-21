#include <iostream>
#include <string>
#include <cctype>

void	toUpperCase(std::string &str)
{
	size_t i = 0;
	while (i < str.length())
	{
		str[i] = std::toupper(str[i]);
		i++;
	}
}

int	main(int argc, char const *argv[])
{
	bool	exit = false;
	std::string	action;

	while (exit == false)
	{
		std::cout << std::endl;
		std::cout << "Please enter the action you would like to perform:" << std::endl;
		std::cout << "-> ADD" << std::endl;
		std::cout << "-> SEARCH" << std::endl;
		std::cout << "-> EXIT" << std::endl;
		std::cout << std::endl;
		std::cin >> action;
		std::cout << std::endl;
		toUpperCase(action);
		if (action == "ADD")
		{
			std::cout << "Add contact" << std::endl;
		}
		else if (action == "SEARCH")
		{
			std::cout << "Search for contact" << std::endl;
		}
		else if (action == "EXIT")
			exit = true;
		else
			std::cout << "Invalid option. Please, enter ADD, SEARCH or EXIT." << std::endl;
				
	}
	return (EXIT_SUCCESS);
}
