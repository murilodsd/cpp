#include "Contact.hpp" 
#include <iostream>

Contact::Contact() :
	first_name(""),
	last_name(""),
	nickname(""),
	phone_number(0),
	darkest_secret("")
{
};

Contact::Contact(std::string first_name, std::string last_name, std::string nickname, int phone_number, std::string darkest_secret) :
	first_name(first_name),
	last_name(last_name),
	nickname(nickname),
	phone_number(phone_number),
	darkest_secret(darkest_secret)
{
	std::cout << "Contact created" <<std::endl;
};

void	Contact::showcontact()
{
	std::cout << this->first_name << " | " << this->last_name << " | " << this->nickname << " | " <<  this->phone_number << " | " << this-> darkest_secret << std::endl;
}
