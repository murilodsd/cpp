#pragma once
#include <iostream>
#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
	// Default constructor
	Ice();

	// Copy constructor
	Ice(const Ice &other);

	// Copy assignment operator overload
	Ice &operator=(const Ice &other);

	// Destructor
	~Ice();

	// Member functions
	AMateria* clone() const;
	void use(ICharacter& target);
};
