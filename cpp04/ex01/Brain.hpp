#pragma once
#include <iostream>
#include <string>

#define RESET "\033[0m"
#define BOLD "\033[1m"
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

class Brain
{
	private:
		std::string ideas[100];

	public:
		// Default constructor
		Brain();

		// Copy constructor
		Brain(const Brain &other);

		// Copy assignment operator overload
		Brain &operator=(const Brain &other);

		// Destructor
		~Brain();
};

#include "Brain.hpp"

// ==================== Constructors ====================
Brain::Brain()
{
	std::cout << GREEN << "Brain default constructor called!" << RESET << std::endl;
}

// ================= Copy Constructor ==================
Brain::Brain(const Brain &other)
:
ideas(other.ideas)
{
	std::cout << GREEN << "Brain copy constructor called!" << RESET << std::endl;
}

// ========== Copy Assignment Operator Overload ==========
Brain &Brain::operator=(const Brain &other)
{
	std::cout << GREEN << "Brain copy assignment operator called!" << RESET << std::endl;
	if (this != &other)
	{
		for (int i = 0; other.ideas->length() < i; i++)
			ideas[i] = other.ideas[i];
	}
	return *this;
}

// ==================== Destructor =====================
Brain::~Brain()
{
	std::cout << RED << "Brain destructor called!" << RESET << std::endl;
}
// ================= Auxiliar Functions =================

// ================== Member Functions ==================
