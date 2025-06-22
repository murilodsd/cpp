#pragma once
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;
	public:
		// Default constructor
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string& target);

		// Copy constructor
		ShrubberyCreationForm(const ShrubberyCreationForm &other);

		// Copy assignment operator overload
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

		// Destructor
		~ShrubberyCreationForm();

		//Others Methods
		void execute(Bureaucrat const & executor) const;
};
