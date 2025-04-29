#include <iostream>
#include <iomanip>
#include "Contact.hpp"
#include "utils.hpp"

Contact::Contact() :
	_first_name(""),
	_last_name(""),
	_nickname(""),
	_phone_number(""),
	_darkest_secret("")
{
};

Contact::Contact(std::string _first_name, std::string _last_name, std::string _nickname, std::string _phone_number, std::string _darkest_secret) :
	_first_name(_first_name),
	_last_name(_last_name),
	_nickname(_nickname),
	_phone_number(_phone_number),
	_darkest_secret(_darkest_secret)
{
	std::cout << "\n";
	std::cout << GREEN << "Contact created!" << std::endl << RESET;
};

void	Contact::show_all_contact_info()
{
	std::cout << BLUE << "*----------------------------------------------------*" << std::endl;
	std::cout << BLUE << "First name: " << WHITE << this->get_first_name() << std::endl;
	std::cout << BLUE << "Last name: " << WHITE << this->get_last_name() << std::endl;
	std::cout << BLUE << "Nickname: " << WHITE << this->get_nickname() << std::endl;
	std::cout << BLUE << "Phone number: " << WHITE << this->get_phone_number() << std::endl;
	std::cout << BLUE << "Darkest secret: " << WHITE << this->get_darkest_secret() << std::endl;
	std::cout << BLUE << "*----------------------------------------------------*" << RESET << std::endl;
}

//******************GETTERS******************

std::string Contact::get_first_name()
{
	return (this->_first_name);
}
std::string Contact::get_last_name()
{
	return (this->_last_name);
}
std::string Contact::get_nickname()
{
	return (this->_nickname);
}
std::string Contact::get_phone_number()
{
	return (this->_phone_number);
}
std::string Contact::get_darkest_secret()
{
	return (this->_darkest_secret);
}

//******************SETTERS******************

void Contact::set_first_name(std::string first_name)
{
	this->_first_name = first_name;
}
void Contact::set_last_name(std::string last_name)
{
	this->_last_name = last_name;
}
void Contact::set_nickname(std::string nickname)
{
	this->_nickname = nickname;
}
void Contact::set_phone_number(std::string phone_number)
{
	this->_phone_number = phone_number;
}
void Contact::set_darkest_secret(std::string darkest_secret)
{
	this->_darkest_secret = darkest_secret;
}
