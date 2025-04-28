#include "PhoneBook.hpp"
#include "utils.hpp"
#include <iomanip>
#include <cstdlib>

PhoneBook::PhoneBook() :
	index(0)
{

};

void	ask_contact_info(std::string &first_name, std::string &last_name, std::string &nickname, \
		std::string &phone_number, std::string &darkest_secret)
{
	utils::getValidInput("Type the first name: ", first_name);
	utils::getValidInput("Type the last name: ", last_name);
	utils::getValidInput("Type the nickname: ", nickname);
	    // Validação para phone_number
	while (true) {
		utils::getValidInput("Type the phone number: ", phone_number);
		if (utils::is_number(phone_number))
			break; // Entrada válida
		std::cout << "Phone number must contain only digits. Please try again." << std::endl;
	}
	utils::getValidInput("Type the darkest secret: ", darkest_secret);
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
		std::cout << YELLOW << "The phonebook is empty" << std::endl << RESET;
	else
	{
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
	utils::getValidInput("Type the index to more info: ", index);
	while (true)
	{
		if (utils::is_number(index))
		{
			if (std::atoi(index.c_str()) >= 0 || std::atoi(index.c_str()) <= max_index)
				break;
		}
		std::cout << RED << "The index must be a number between 0 an " << max_index << std::endl << RESET;
		utils::getValidInput("Type the index to more info: ", index);
	}
	std::cout << std::endl;
	this->show_contact(std::atoi(index.c_str()));
	}
}

void	PhoneBook::show_contact(int index)
{
	this->contacts[index].show_all_contact_info();
}