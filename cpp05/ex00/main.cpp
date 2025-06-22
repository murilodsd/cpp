#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	std::cout << "=== CPP05 EX00 - Bureaucrat Tests ===" << std::endl;
	
	try {
		std::cout << CYAN << "\n1. Testing normal bureaucrat creation (75):" << RESET << std::endl;
		Bureaucrat bob("Bob", 75);
		std::cout << bob << std::endl;
		
		std::cout << CYAN << "\n2. Testing bureaucrat with highest grade (1):" << RESET << std::endl;
		Bureaucrat alice("Alice", 1);
		std::cout << alice << std::endl;
		
		std::cout << CYAN << "\n3. Testing bureaucrat with lowest grade (150):" << RESET << std::endl;
		Bureaucrat charlie("Charlie", 150);
		std::cout << charlie << std::endl;
		
		std::cout << CYAN << "\n4. Testing increment grade:" << RESET << std::endl;
		bob.incrementGrade();
		std::cout << "After increment: " << bob << std::endl;
		
		std::cout << CYAN << "\n5. Testing decrement grade:" << RESET << std::endl;
		bob.decrementGrade();
		std::cout << "After decrement: " << bob << std::endl;
		
	} catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	
	try {
		std::cout << CYAN << "\n6. Testing grade too high exception (grade 0):" << RESET << std::endl;
		Bureaucrat invalid1("Invalid1", 0);
	} catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	
	try {
		std::cout << CYAN << "\n7. Testing grade too low exception (grade 151):" << RESET << std::endl;
		Bureaucrat invalid2("Invalid2", 151);
	} catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	
	try {
		std::cout << CYAN << "\n8. Testing increment on highest grade:" << RESET << std::endl;
		Bureaucrat topBureaucrat("Top", 1);
		std::cout << "Before increment: " << topBureaucrat << std::endl;
		topBureaucrat.incrementGrade();
	} catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	
	try {
		std::cout << CYAN << "\n9. Testing decrement on lowest grade:" << RESET << std::endl;
		Bureaucrat bottomBureaucrat("Bottom", 150);
		std::cout << "Before decrement: " << bottomBureaucrat << std::endl;
		bottomBureaucrat.decrementGrade();
	} catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	
	std::cout << CYAN << "\n=== End of tests ===" << RESET << std::endl;
	return 0;
}