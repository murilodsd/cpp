#include "PhoneBook.hpp"
#include "utils.hpp"
#include <iomanip>
#include <cstdlib>

PhoneBook::PhoneBook() :
	index(0)
{
	std::cout << CYAN << "*----------------------------------------------------*" << std::endl;
	std::cout << "-----------------Phone Book Created!------------------" << std::endl;
	std::cout << "*----------------------------------------------------*" << RESET << std::endl;
};

void	ask_contact_info(std::string &first_name, std::string &last_name, std::string &nickname, \
		std::string &phone_number, std::string &darkest_secret)
{
	std::cout << CYAN << "---------------------New Contact!---------------------" << RESET << std::endl;
	std::cout << std::endl;
	utils::getValidAlphaInput("Type the first name: ", first_name, WHITESPACE_CHARS);
	utils::getValidAlphaInput("Type the last name: ", last_name, WHITESPACE_CHARS);
	utils::getValidInput("Type the nickname: ", nickname, WHITESPACE_CHARS);
	utils::getValidIntegerInput("Type the phone number: ", phone_number, "");
	utils::getValidInput("Type the darkest secret: ", darkest_secret, "");
}

void PhoneBook::insert_in_phonebook(std::string _first_name, std::string _last_name, std::string _nickname, std::string _phone_number, std::string _darkest_secret)
{
	Contact contact(_first_name, _last_name, _nickname, _phone_number, _darkest_secret);

	this->contacts[index] = contact;
	if (this->index < 7)
		this->index++;
	else
		this->index = 0;
};

void	PhoneBook::add_contact(PhoneBook &phonebook)
{
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

	ask_contact_info(first_name, last_name, nickname, phone_number, darkest_secret);
	phonebook.insert_in_phonebook(first_name, last_name, nickname, phone_number, darkest_secret);
}

void	print_str(std::string str)
{
	if (str.length() <= 10)
		std::cout << std::setw(10) << str;
	else
		std::cout << str.substr(0, 9) << ".";
}

bool	list_contact(Contact contact, int index)
{
	std::cout << std::setw(10) << index << "|";
	print_str(contact.get_first_name());
	std::cout << "|";
	print_str(contact.get_last_name());
	std::cout << "|";
	print_str(contact.get_nickname());
	std::cout << std::endl;
	return (true);
}

int	PhoneBook::show_all_contacts()
{
	int	i;
	
	i = 0;
	if (this->contacts[i].get_first_name() == "")
		std::cout << YELLOW << "The phone book is empty" << std::endl << RESET;
	else
	{
		std::cout << CYAN "----------------All Phone Book Contacts---------------" << RESET << std::endl;
		std::cout << std::endl;
		std::cout << std::setw(10) << "Index" << "|";
		std::cout << "First name" << "|";
		std::cout << std::setw(10) << "Last name" << "|";
		std::cout << std::setw(10) << "Nickname" << std::endl;
		while (i < 8)
		{
			if (this->contacts[i].get_first_name() == "")
				break;
			list_contact(this->contacts[i], i);
			i++;
		}
	}
	return (i - 1);
}

void	PhoneBook::search()
{
	std::string	index;
	int	max_index;

	max_index = this->show_all_contacts();
	index = "-1";
	if (max_index != -1)
	{
		std::cout << std::endl;
		utils::getValidIntegerInput("Type the index to more info: ", index, "");
		while (true)
		{
			if (std::atoi(index.c_str()) >= 0 && std::atoi(index.c_str()) <= max_index)
					break;
			std::cout << RED << "The index must be a number between 0 an " << max_index << std::endl << RESET;
			utils::getValidIntegerInput("Type the index to more info: ", index, "");
		}
		std::cout << std::endl;
		this->show_contact(std::atoi(index.c_str()));
	}
}

void	PhoneBook::show_contact(int index)
{
	this->contacts[index].show_all_contact_info();
}