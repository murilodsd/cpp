#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
	std::cout << "=== CPP05 EX01 - Form Tests ===" << std::endl;
	
	try {
		std::cout << CYAN << "\n1. Testing form creation (name: Contract, signGrade: 50, execGrade: 25):" << RESET << std::endl;
		Form form1("Contract", 50, 25);
		std::cout << form1 << std::endl;
		
		std::cout << CYAN << "\n2. Testing bureaucrat signing form (Alice grade: 30, form signGrade: 50):" << RESET << std::endl;
		Bureaucrat alice("Alice", 30);
		std::cout << "Bureaucrat: " << alice << std::endl;
		std::cout << "Before signing: " << form1 << std::endl;
		alice.signForm(form1);
		std::cout << "After signing: " << form1 << std::endl;
		
	} catch (std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	
	try {
		std::cout << CYAN << "\n3. Testing bureaucrat signing form (Bob grade: 75, form signGrade: 10):" << RESET << std::endl;
		Form form2("Important Document", 10, 5);
		Bureaucrat bob("Bob", 75);
		std::cout << form2 << std::endl;
		std::cout << "Bureaucrat: " << bob << std::endl;
		bob.signForm(form2);
		
	} catch (std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	
	try {
		std::cout << CYAN << "\n4. Testing signing already signed form (Charlie grade: 35, form signGrade: 40):" << RESET << std::endl;
		Form form3("License", 40, 20);
		Bureaucrat charlie("Charlie", 35);
		charlie.signForm(form3);
		charlie.signForm(form3); // Try to sign again
		
	} catch (std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	
	try {
		std::cout << CYAN << "\n5. Testing form with invalid grade (signGrade: 0, execGrade: 50):" << RESET << std::endl;
		Form invalidForm1("Invalid", 0, 50);
		
	} catch (std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	
	try {
		std::cout << CYAN << "\n6. Testing form with invalid grade (signGrade: 50, execGrade: 151):" << RESET << std::endl;
		Form invalidForm2("Invalid", 50, 151);
		
	} catch (std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	
	std::cout << CYAN << "\n=== End of tests ===" << RESET << std::endl;
	return 0;
}