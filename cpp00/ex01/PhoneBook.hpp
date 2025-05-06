#pragma once
#include <string>
#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact	contacts[8];
		int	index;
	public:
		PhoneBook();
		void	insert_in_phonebook(std::string first_name, std::string last_name, \
			std::string nickname, std::string phone_number, std::string darkest_secret);
		void	add_contact(PhoneBook &phonebook);
		int	show_all_contacts();
		void	search();
		void	show_contact(int index);
};