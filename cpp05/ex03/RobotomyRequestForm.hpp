#pragma once
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string _target;
	public:
		// Default constructor
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string& target);

		// Copy constructor
		RobotomyRequestForm(const RobotomyRequestForm &other);

		// Copy assignment operator overload
		RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

		// Destructor
		~RobotomyRequestForm();

		//Others Methods
		void execute(Bureaucrat const & executor) const;
};
