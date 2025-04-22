#pragma once
#include <iostream>

class Contact
{
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		int phone_number;
		std::string darkest_secret;
	public:
		Contact();
		Contact(std::string first_name, std::string last_name, std::string nickname, int phone_number, std::string darkest_secret);
		void showcontact();
};