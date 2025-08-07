#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <exception>

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
# define WHITE "\033[37m"
#endif

int main()
{
	// Initialize the random number generator once at the beginning.
	std::srand(std::time(0));

	std::cout << YELLOW << "--- Subject Test ---" << RESET << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	std::cout << YELLOW << "--------------------" << RESET << std::endl << std::endl;

	std::cout << YELLOW << "--- Exception Tests ---" << RESET << std::endl;
	std::cout << "Testing adding more than capacity..." << std::endl;
	try {
		sp.addNumber(42);
	} catch (const std::exception& e) {
		std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
	}

	std::cout << "\nTesting shortestSpan with insufficient numbers..." << std::endl;
	Span sp2(2);
	sp2.addNumber(1);
	try {
		std::cout << sp2.shortestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
	}

	std::cout << "\nTesting longestSpan with insufficient numbers..." << std::endl;
	try {
		std::cout << sp2.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
	}
	std::cout << YELLOW << "-----------------------" << RESET << std::endl << std::endl;

	std::cout << YELLOW << "--- Large Scale Test (10,000 numbers) ---" << RESET << std::endl;
	try {
		Span sp3(10000);
		// Adding a range of numbers using the addRange method.
		std::vector<int> numbers;
		for (int i = 0; i < 10000; ++i)
		{
			numbers.push_back(i * 3);
		}
		sp3.addRange(numbers.begin(), numbers.end());
		std::cout << GREEN << "Bulk insert successful." << RESET << std::endl;
		std::cout << "Shortest span: " << GREEN << sp3.shortestSpan() << RESET << std::endl;
		std::cout << "Longest span: " << GREEN << sp3.longestSpan() << RESET << std::endl;
	} catch (const std::exception& e) {
		std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
	}
	std::cout << YELLOW << "-------------------------------------------" << RESET << std::endl << std::endl;

	std::cout << YELLOW << "--- Large Scale Test (20,000 random numbers) ---" << RESET << std::endl;
	std::cout << "(This may be very slow due to sorting on each add)" << std::endl;
	try {
		Span sp4(20000);
		// Adding one by one.
		std::vector<int> random_numbers;
		for (int i = 0; i < 20000; ++i)
		{
			random_numbers.push_back(std::rand());
		}
		sp4.addRange(random_numbers.begin(), random_numbers.end());
		std::cout << GREEN << "Bulk insert successful." << RESET << std::endl;
		std::cout << "Shortest span: " << GREEN << sp4.shortestSpan() << RESET << std::endl;
		std::cout << "Longest span: " << GREEN << sp4.longestSpan() << RESET << std::endl;
	} catch (const std::exception& e) {
		std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
	}
	std::cout << YELLOW << "---------------------------------------------------" << RESET << std::endl << std::endl;
	
	std::cout << YELLOW << "--- Canonical Form Test ---" << RESET << std::endl;
	Span original(5);
	original.addNumber(10);
	original.addNumber(20);
	original.addNumber(30);

	// Copy constructor test
	Span copy = original;
	
	// Assignment operator test
	Span assigned(2);
	assigned = original;

	std::cout << "Original longest span: " << GREEN << original.longestSpan() << RESET << std::endl;
	std::cout << "Copy longest span: " << GREEN << copy.longestSpan() << RESET << std::endl;
	std::cout << "Assigned longest span: " << GREEN << assigned.longestSpan() << RESET << std::endl;
	
	std::cout << "\nModifying original to check for deep copy..." << std::endl;
	try {
		original.addNumber(0);
		original.addNumber(40);
	} catch (const std::exception& e) {
		std::cout << RED << "Exception on modification: " << e.what() << RESET << std::endl;
	}

	std::cout << "Original longest span after mod: " << GREEN << original.longestSpan() << RESET << std::endl;
	std::cout << "Copy longest span after mod: " << GREEN << copy.longestSpan() << RESET << std::endl;
	std::cout << "Assigned longest span after mod: " << GREEN << assigned.longestSpan() << RESET << std::endl;
	std::cout << YELLOW << "---------------------------" << RESET << std::endl;

	return 0;
}