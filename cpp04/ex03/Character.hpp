#pragma once
#include <iostream>
#include "AMateria.hpp"

class Character : public ICharacter
{
	private:
		std::string _name;
		AMateria* _inventory[4];
	public:
		// Default constructor
		Character();
		Character(std::string name);

		// Copy constructor
		Character(const Character &other);

		// Copy assignment operator overload
		Character &operator=(const Character &other);

		// Destructor
		~Character();

		//Merber Functions
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};
