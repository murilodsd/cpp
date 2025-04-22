#pragma once
#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact	contacts[8];
		int	index;
	public:
		PhoneBook();
		void add(std::string first_name, std::string last_name, std::string nickname, int phone_number, std::string darkest_secret);
		void showcontact(int index);
};