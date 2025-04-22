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

void	add(PhoneBook &phonebook)
{
	std::string first_name;
	std::string last_name;
	std::string nickname;
	int phone_number;
	std::string darkest_secret;

	std::cout << "Type the first name" << std::endl;
	std::cin >> first_name;
	std::cout << "Type the last name" << std::endl;
	std::cin >> last_name;
	std::cout << "Type the nickname" << std::endl;
	std::cin >> nickname;
	std::cout << "Type the phone number" << std::endl;
	std::cin >> phone_number;
	std::cout << "Type the darkest secret" << std::endl;
	std::cin >> darkest_secret;
	phonebook.add(first_name, last_name, nickname, phone_number, darkest_secret);
}

int	main(int argc, char const *argv[])
{
	bool	exit = false;
	std::string	action;
	PhoneBook phonebook;

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
			add(phonebook);
		}
		else if (action == "SEARCH")
		{
			std::cout << "Search for contact" << std::endl;
			phonebook.showcontact(0);
			phonebook.showcontact(1);
		}
		else if (action == "EXIT")
			exit = true;
		else
			std::cout << "Invalid option. Please, enter ADD, SEARCH or EXIT." << std::endl;
				
	}
	return (EXIT_SUCCESS);
}
