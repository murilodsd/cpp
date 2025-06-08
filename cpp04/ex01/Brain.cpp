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
