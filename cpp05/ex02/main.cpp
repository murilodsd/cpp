#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include <iostream>

int main()
{
	std::cout << "=== CPP05 EX02 - Concrete Forms Tests ===" << std::endl;
	
	try {
		std::cout << CYAN << "\n1. Testing ShrubberyCreationForm:" << RESET << std::endl;
		std::cout << CYAN << "   Parameters: target='garden', sign_grade=145, exec_grade=137" << RESET << std::endl;
		std::cout << CYAN << "   Bureaucrat: name='Alice', grade=130" << RESET << std::endl;
		ShrubberyCreationForm shrub("garden");
		Bureaucrat alice("Alice", 130);
		std::cout << shrub << std::endl;
		std::cout << alice << std::endl;
		
		alice.signForm(shrub);
		alice.executeForm(shrub);
		
	} catch (std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	
	try {
		std::cout << CYAN << "\n2. Testing RobotomyRequestForm:" << RESET << std::endl;
		std::cout << CYAN << "   Parameters: target='Bender', sign_grade=72, exec_grade=45" << RESET << std::endl;
		std::cout << CYAN << "   Bureaucrat: name='Bob', grade=1" << RESET << std::endl;
		RobotomyRequestForm robot("Bender");
		Bureaucrat bob("Bob", 1);
		std::cout << robot << std::endl;
		std::cout << bob << std::endl;
		
		bob.signForm(robot);
		bob.executeForm(robot);
		bob.executeForm(robot); // Try again to see randomness
		
	} catch (std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	
	try {
		std::cout << CYAN << "\n3. Testing PresidentialPardonForm:" << RESET << std::endl;
		std::cout << CYAN << "   Parameters: target='Criminal', sign_grade=25, exec_grade=5" << RESET << std::endl;
		std::cout << CYAN << "   Bureaucrat: name='Charlie', grade=5" << RESET << std::endl;
		PresidentialPardonForm pardon("Criminal");
		Bureaucrat charlie("Charlie", 5);
		std::cout << pardon << std::endl;
		std::cout << charlie << std::endl;
		
		charlie.signForm(pardon);
		charlie.executeForm(pardon);
		
	} catch (std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	
	try {
		std::cout << CYAN << "\n4. Testing execution without signing:" << RESET << std::endl;
		std::cout << CYAN << "   Parameters: target='test', sign_grade=145, exec_grade=137" << RESET << std::endl;
		std::cout << CYAN << "   Bureaucrat: name='Dave', grade=100" << RESET << std::endl;
		ShrubberyCreationForm unsignedForm("test");
		Bureaucrat dave("Dave", 100);
		dave.executeForm(unsignedForm);
		
	} catch (std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	
	try {
		std::cout << CYAN << "\n5. Testing execution with insufficient grade:" << RESET << std::endl;
		std::cout << CYAN << "   Parameters: target='Target', sign_grade=25, exec_grade=5" << RESET << std::endl;
		std::cout << CYAN << "   Bureaucrat: name='Eve', grade=25" << RESET << std::endl;
		PresidentialPardonForm hardForm("Target");
		Bureaucrat eve("Eve", 25);
		eve.signForm(hardForm);
		eve.executeForm(hardForm);
		
	} catch (std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	
	std::cout << CYAN << "\n=== End of tests ===" << RESET << std::endl;
	return 0;
}