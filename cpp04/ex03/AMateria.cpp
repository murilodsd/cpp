#include "AMateria.hpp"

// ==================== Constructors ====================
AMateria::AMateria()
{
	std::cout << GREEN << "AMateria default constructor called!" << RESET << std::endl;
}

AMateria::AMateria(std::string const & type)
:
_type(type)
{
	std::cout << GREEN << "AMateria string constructor called!" << RESET << std::endl;
}

// ================= Copy Constructor ==================
AMateria::AMateria(const AMateria &other)
:
_type(other._type)
{
	std::cout << GREEN << "AMateria copy constructor called!" << RESET << std::endl;
}

// ========== Copy Assignment Operator Overload ==========
AMateria &AMateria::operator=(const AMateria &other)
{
	std::cout << GREEN << "AMateria copy assignment operator called!" << RESET << std::endl;
	if (this != &other)
	{
		_type = other._type;
	}
    return *this;
}

// ==================== Destructor =====================
AMateria::~AMateria()
{
std::cout << RED << "AMateria destructor called!" << RESET << std::endl;
}
// ================= Auxiliar Functions =================

// ================== Member Functions ==================

std::string const & AMateria::getType() const
{
	return (_type);
}