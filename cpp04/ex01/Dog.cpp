#include "Dog.hpp"
#include <iostream>

// ==================== Constructors ====================
Dog::Dog()
:
Animal("Dog")
{
	brain = new Brain();
	std::cout << GREEN << "Dog default constructor called!" << RESET << std::endl;
}

// ================= Copy Constructor ==================
Dog::Dog(const Dog &other)
:
Animal(other._type)
{
	std::cout << GREEN << "Dog copy constructor called!" << RESET << std::endl;
}

// ========== Copy Assignment Operator Overload ==========
Dog &Dog::operator=(const Dog &other)
{
	std::cout << GREEN << "Dog copy assignment operator called!" << RESET << std::endl;
	if (this != &other)
	{
		_type = other._type;
	}
	return *this;
}

// ==================== Destructor =====================
Dog::~Dog()
{
	std::cout << RED << "Dog destructor called!" << RESET << std::endl;
}
// ================= Auxiliar Functions =================

// ================== Member Functions ==================
void Dog::makeSound() const
{
	std::cout << CYAN << "Woof! Woof!" << RESET << std::endl;
}
