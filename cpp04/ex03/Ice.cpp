#include "Ice.hpp"
#include "ICharacter.hpp"

// ==================== Constructors ====================
Ice::Ice()
:
AMateria("ice")
{
	std::cout << GREEN << "Ice default constructor called!" << RESET << std::endl;
}

// ================= Copy Constructor ==================
Ice::Ice(const Ice &other)
:
AMateria(other._type)
{
	std::cout << GREEN << "Ice copy constructor called!" << RESET << std::endl;
}

// ========== Copy Assignment Operator Overload ==========
Ice &Ice::operator=(const Ice &other)
{
	std::cout << GREEN << "Ice copy assignment operator called!" << RESET << std::endl;
	(void)other;
	return *this;
}

// ==================== Destructor =====================
Ice::~Ice()
{
	std::cout << RED << "Ice destructor called!" << RESET << std::endl;
}
// ================= Auxiliar Functions =================

// ================== Member Functions ==================
AMateria* Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}