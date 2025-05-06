#pragma once
#include <string>
#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact	contacts[8];
		int	index;
		void	show_contact(int index);
		int	show_all_contacts();
		void	insert_in_phonebook(std::string first_name, std::string last_name, \
			std::string nickname, std::string phone_number, std::string darkest_secret);
	public:
		PhoneBook();
		void	add_contact(PhoneBook &phonebook);
		void	search();
};