#include "Cat.hpp"
#include <iostream>

// ==================== Constructors ====================
Cat::Cat()
:
Animal("Cat")
{
	std::cout << GREEN << "Cat default constructor called!" << RESET << std::endl;
}

// ================= Copy Constructor ==================
Cat::Cat(const Cat &other)
:
Animal(other._type)
{
	std::cout << GREEN << "Cat copy constructor called!" << RESET << std::endl;
}

// ========== Copy Assignment Operator Overload ==========
Cat &Cat::operator=(const Cat &other)
{
	std::cout << GREEN << "Cat copy assignment operator called!" << RESET << std::endl;
	if (this != &other)
	{
		_type = other._type;
	}
	return *this;
}

// ==================== Destructor =====================
Cat::~Cat()
{
	std::cout << RED << "Cat destructor called!" << RESET << std::endl;
}
// ================= Auxiliar Functions =================

// ================== Member Functions ==================
void Cat::makeSound() const
{
	std::cout << CYAN << "Meow!" << RESET << std::endl;
}
