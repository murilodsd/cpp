#include "Brain.hpp"

// ==================== Constructors ====================
Brain::Brain()
{
	std::cout << GREEN << "Brain default constructor called!" << RESET << std::endl;
}

// ================= Copy Constructor ==================
Brain::Brain(const Brain &other)
{
	std::cout << GREEN << "Brain copy constructor called!" << RESET << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = other.ideas[i];
}

// ========== Copy Assignment Operator Overload ==========
Brain &Brain::operator=(const Brain &other)
{
	std::cout << GREEN << "Brain copy assignment operator called!" << RESET << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
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
void Brain::setIdea(int index, const std::string& idea)
{
	if (index >= 0 && index < 100)
		ideas[index] = idea;
}

const std::string& Brain::getIdea(int index) const
{
	if (index >= 0 && index < 100)
		return ideas[index];
	static const std::string empty = "";
	return empty;
}
