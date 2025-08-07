#include "MutantStack.hpp"

 #ifndef COLORS
 # define COLORS
 # define RESET "\033[0m"
 # define BOLD "\033[1m"
 # define BLACK "\033[30m"
 # define RED "\033[31m"
 # define GREEN "\033[32m"
 # define YELLOW "\033[33m"
 # define BLUE "\033[34m"
 # define MAGENTA "\033[35m"
 # define CYAN "\033[36m"
 # define WHITE "\033[37m"
 #endif

int main(void)
{
	std::cout << BOLD << CYAN << "=== MUTANT STACK TESTS ===" << RESET << std::endl << std::endl;

	// Test 1: Basic operations
	std::cout << BOLD << "Test 1: Basic Stack Operations" << RESET << std::endl;
	MutantStack<int> ms;
	
	std::cout << "Pushing elements: 5, 17, 3, 5, 737, 0" << std::endl;
	ms.push(5);
	ms.push(17);
	ms.push(3);
	ms.push(5);
	ms.push(737);
	ms.push(0);
	
	std::cout << "Stack size: " << ms.size() << std::endl;
	std::cout << "Top element: " << ms.top() << std::endl;
	
	ms.pop();
	std::cout << "After pop - Top element: " << ms.top() << std::endl;
	std::cout << "Stack size: " << ms.size() << std::endl;
	std::cout << std::endl;

	// Test 2: Iterator functionality
	std::cout << BOLD << "Test 2: Iterator Functionality" << RESET << std::endl;
	std::cout << "Iterating through stack (begin to end):" << std::endl;
	MutantStack<int>::iterator it = ms.begin();
	MutantStack<int>::iterator ite = ms.end();
	while (it != ite)
	{
		std::cout << GREEN << *it << RESET << " ";
		++it;
	}
	std::cout << std::endl << std::endl;

	// Test 3: Comparing with std::stack
	std::cout << BOLD << "Test 3: Comparison with std::stack" << RESET << std::endl;
	std::cout << "Created std::stack from MutantStack" << std::endl;
	std::stack<int> s(ms);
	std::cout << "std::stack size: " << s.size() << std::endl;
	std::cout << "std::stack top: " << s.top() << std::endl;
	std::cout << std::endl;

	// Test 4: String type test
	std::cout << BOLD << "Test 4: String Type Test" << RESET << std::endl;
	MutantStack<std::string> ms_str;
	ms_str.push("Hello");
	ms_str.push("World");
	ms_str.push("42");
	ms_str.push("School");
	
	std::cout << "String stack contents:" << std::endl;
	for (MutantStack<std::string>::iterator it_str = ms_str.begin(); it_str != ms_str.end(); ++it_str)
	{
		std::cout << YELLOW << *it_str << RESET << " ";
	}
	std::cout << std::endl << std::endl;

	// Test 5: Copy constructor and assignment
	std::cout << BOLD << "Test 5: Copy Constructor and Assignment" << RESET << std::endl;
	MutantStack<int> ms_copy(ms);
	std::cout << "Copied stack contents:" << std::endl;
	for (MutantStack<int>::iterator it_copy = ms_copy.begin(); it_copy != ms_copy.end(); ++it_copy)
	{
		std::cout << *it_copy << " ";
	}
	std::cout << std::endl;
	
	MutantStack<int> ms_assign;
	ms_assign = ms;
	std::cout << "Assigned stack contents:" << std::endl;
	for (MutantStack<int>::iterator it_assign = ms_assign.begin(); it_assign != ms_assign.end(); ++it_assign)
	{
		std::cout << *it_assign << " ";
	}
	std::cout << std::endl << std::endl;

	// Test 6: Const Correctness
	std::cout << BOLD << "Test 6: Const Correctness" << RESET << std::endl;
	const MutantStack<int> const_ms(ms_assign);
	std::cout << "Iterating through a const MutantStack:" << std::endl;
	
	MutantStack<int>::const_iterator it_const = const_ms.begin();
	MutantStack<int>::const_iterator ite_const = const_ms.end();
	while (it_const != ite_const)
	{
		std::cout << MAGENTA << *it_const << RESET << " ";
		++it_const;
	}
	std::cout << std::endl << std::endl;

	std::cout << BOLD << CYAN << "=== ALL TESTS COMPLETED ===" << RESET << std::endl;
	return 0;
}
