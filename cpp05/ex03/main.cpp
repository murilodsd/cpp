#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include <iostream>
#include "Intern.hpp"

int main()
{
	std::cout << "=== CPP05 EX03 - Intern Tests ===" << std::endl;
	
	try {
		std::cout << CYAN << "\n1. Testing Intern creating ShrubberyCreationForm:" << RESET << std::endl;
		Intern intern;
		Bureaucrat boss("Boss", 1);
		
		AForm* form1 = intern.makeForm("shrubbery creation", "garden");
		if (form1) {
			std::cout << *form1 << std::endl;
			boss.signForm(*form1);
			boss.executeForm(*form1);
			delete form1;
		}
		
	} catch (std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	
	try {
		std::cout << CYAN << "\n2. Testing Intern creating RobotomyRequestForm:" << RESET << std::endl;
		Intern intern;
		Bureaucrat boss("Boss", 1);
		
		AForm* form2 = intern.makeForm("robotomy request", "Bender");
		if (form2) {
			std::cout << *form2 << std::endl;
			boss.signForm(*form2);
			boss.executeForm(*form2);
			delete form2;
		}
		
	} catch (std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	
	try {
		std::cout << CYAN << "\n3. Testing Intern creating PresidentialPardonForm:" << RESET << std::endl;
		Intern intern;
		Bureaucrat boss("Boss", 1);
		
		AForm* form3 = intern.makeForm("presidential pardon", "Criminal");
		if (form3) {
			std::cout << *form3 << std::endl;
			boss.signForm(*form3);
			boss.executeForm(*form3);
			delete form3;
		}
		
	} catch (std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	
	try {
		std::cout << CYAN << "\n4. Testing Intern with invalid form name:" << RESET << std::endl;
		Intern intern;
		
		AForm* invalidForm = intern.makeForm("invalid form", "target");
		if (invalidForm) {
			delete invalidForm;
		}
		
	} catch (std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	
	std::cout << CYAN << "\n=== End of Intern tests ===" << RESET << std::endl;
	return 0;
}