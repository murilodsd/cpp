#include "PhoneBook.hpp"
#include <iomanip>

PhoneBook::PhoneBook() :
	index(0)
{

};

void	ask_contact_info(std::string &first_name, std::string &last_name, std::string &nickname, \
		std::string &phone_number, std::string &darkest_secret)
{
	first_name = "";
	last_name = "";
	nickname = "";
	phone_number = "";
	darkest_secret = "";
	std::cout << "Type the first name: ";
	std::cin >> first_name;
	std::cout << "Type the last name: ";
	std::cin >> last_name;
	std::cout << "Type the nickname: ";
	std::cin >> nickname;
	std::cout << "Type the phone number: ";
	std::cin >> phone_number;
	std::cout << "Type the darkest secret: ";
	std::cin >> darkest_secret;
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
	std::cout << "Type the index to more info: ";
	std::cin >> index;
	while (std::stoi(index) < 0 || std::stoi(index) > max_index)
	{
		std::cout << RED << "The index must be a number between 0 an " << max_index << std::endl << RESET;
		std::cout << "Type the index to more info: ";
		std::cin >> index;
	}
	std::cout << std::endl;
	this->show_contact(std::stoi(index));
	}
}

void	PhoneBook::show_contact(int index)
{
	this->contacts[index].show_all_contact_info();
}