#pragma once
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string _target;
	public:
		// Default constructor
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string& target);

		// Copy constructor
		PresidentialPardonForm(const PresidentialPardonForm &other);

		// Copy assignment operator overload
		PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

		// Destructor
		~PresidentialPardonForm();

		//Others Methods
		void execute(Bureaucrat const & executor) const;
};
