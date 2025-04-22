#include "PhoneBook.hpp"

PhoneBook::PhoneBook() :
	index(0)
{

};

void PhoneBook::add(std::string first_name, std::string last_name, std::string nickname, int phone_number, std::string darkest_secret)
{
	Contact contact(first_name, last_name, nickname, phone_number, darkest_secret);
	this->contacts[index] = contact;
	if (this->index < 7)
		this->index++;
	else
		this->index = 0;
};

void PhoneBook::showcontact(int index)
{
	this->contacts[index].showcontact();
}