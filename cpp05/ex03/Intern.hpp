#pragma once
#include <iostream>
#include "AForm.hpp"

class Intern
{	
	private:
		AForm* createShrubbery(const std::string& target);
		AForm* createRobotomy(const std::string& target);
		AForm* createPresidential(const std::string& target);

	public:
		// Default constructor
		Intern();

		// Copy constructor
		Intern(const Intern &other);

		// Copy assignment operator overload
		Intern &operator=(const Intern &other);

		// Destructor
		~Intern();

		//Others Methods
		AForm* makeForm(const std::string& name, const std::string& target);
};
