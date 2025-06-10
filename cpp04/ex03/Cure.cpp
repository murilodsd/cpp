#include "Cure.hpp"
#include "ICharacter.hpp"

// ==================== Constructors ====================
Cure::Cure()
:
AMateria("cure")
{
	std::cout << GREEN << "Cure default constructor called!" << RESET << std::endl;
}

// ================= Copy Constructor ==================
Cure::Cure(const Cure &other)
:
AMateria(other._type)
{
	std::cout << GREEN << "Cure copy constructor called!" << RESET << std::endl;
}

// ========== Copy Assignment Operator Overload ==========
Cure &Cure::operator=(const Cure &other)
{
	std::cout << GREEN << "Cure copy assignment operator called!" << RESET << std::endl;
	(void)other;
	return *this;
}

// ==================== Destructor =====================
Cure::~Cure()
{
	std::cout << RED << "Cure destructor called!" << RESET << std::endl;
}
// ================= Auxiliar Functions =================

// ================== Member Functions ==================
AMateria* Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* shoots an cure bolt at " << target.getName() << " *" << std::endl;
}