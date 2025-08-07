#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

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

int main() {
	std::cout << YELLOW BOLD << "----- TESTING VECTOR -----" << RESET << std::endl;
	std::vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);
	vec.push_back(50);
	std::cout << "Vector contents: ";
	for (std::vector<int>::size_type i = 0; i < vec.size(); ++i)
		std::cout << BLUE << vec[i] << " " << RESET;
	std::cout << std::endl;

	std::cout << "Trying to find 30 in vector..." << std::endl;
	if (easyfind(vec, 30) != vec.end())
		std::cout << GREEN << "Found 30 in vector!" << RESET << std::endl;
	else
		std::cout << RED << "30 not found in vector." << RESET << std::endl;

	std::cout << "Trying to find 99 in vector..." << std::endl;
	if (easyfind(vec, 99) != vec.end())
		std::cout << GREEN << "Found 99 in vector!" << RESET << std::endl;
	else
		std::cout << RED << "99 not found in vector." << RESET << std::endl;

	std::cout << YELLOW BOLD << "\n----- TESTING LIST -----" << RESET << std::endl;
	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(15);
	lst.push_back(25);
	lst.push_back(35);
	std::cout << "List contents: ";
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
		std::cout << BLUE << *it << " " << RESET;
	std::cout << std::endl;

	std::cout << "Trying to find 15 in list..." << std::endl;
	if (easyfind(lst, 15) != lst.end())
		std::cout << GREEN << "Found 15 in list!" << RESET << std::endl;
	else
		std::cout << RED << "15 not found in list." << RESET << std::endl;

	std::cout << "Trying to find 100 in list..." << std::endl;
	if (easyfind(lst, 100) != lst.end())
		std::cout << GREEN << "Found 100 in list!" << RESET << std::endl;
	else
		std::cout << RED << "100 not found in list." << RESET << std::endl;

	std::cout << YELLOW BOLD << "\n----- TESTING DEQUE -----" << RESET << std::endl;
	std::deque<int> deq;
	deq.push_back(7);
	deq.push_back(14);
	deq.push_back(21);
	deq.push_back(28);
	std::cout << "Deque contents: ";
	for (std::deque<int>::size_type i = 0; i < deq.size(); ++i)
		std::cout << BLUE << deq[i] << " " << RESET;
	std::cout << std::endl;

	std::cout << "Trying to find 21 in deque..." << std::endl;
	if (easyfind(deq, 21) != deq.end())
		std::cout << GREEN << "Found 21 in deque!" << RESET << std::endl;
	else
		std::cout << RED << "21 not found in deque." << RESET << std::endl;

	std::cout << "Trying to find 0 in deque..." << std::endl;
	if (easyfind(deq, 0) != deq.end())
		std::cout << GREEN << "Found 0 in deque!" << RESET << std::endl;
	else
		std::cout << RED << "0 not found in deque." << RESET << std::endl;

	std::cout << YELLOW BOLD << "\n----- TESTING CONST CONTAINER -----" << RESET << std::endl;
	const std::vector<int> const_vec(vec);
	std::cout << "Const vector contents: ";
	for (std::vector<int>::size_type i = 0; i < const_vec.size(); ++i)
		std::cout << BLUE << const_vec[i] << " " << RESET;
	std::cout << std::endl;

	std::cout << "Trying to find 20 in const vector..." << std::endl;
	if (easyfind(const_vec, 20) != const_vec.end())
		std::cout << GREEN << "Found 20 in const vector!" << RESET << std::endl;
	else
		std::cout << RED << "20 not found in const vector." << RESET << std::endl;

	std::cout << "Trying to find 77 in const vector..." << std::endl;
	if (easyfind(const_vec, 77) != const_vec.end())
		std::cout << GREEN << "Found 77 in const vector!" << RESET << std::endl;
	else
		std::cout << RED << "77 not found in const vector." << RESET << std::endl;

	return 0;
}
