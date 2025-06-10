#pragma once
#include <iostream>
#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
	// Default constructor
	Cure();

	// Copy constructor
	Cure(const Cure &other);

	// Copy assignment operator overload
	Cure &operator=(const Cure &other);

	// Destructor
	~Cure();

	// Member functions
	AMateria* clone() const;
	void use(ICharacter& target);
};
