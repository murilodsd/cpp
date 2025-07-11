#pragma once
#include <string>
#include "Animal.hpp"

#define RESET "\033[0m"
#define BOLD "\033[1m"
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

class Dog : public Animal
{
	public:
		// Default constructor
		Dog();

		// Copy constructor
		Dog(const Dog &other);

		// Copy assignment operator overload
		Dog &operator=(const Dog &other);

		// Destructor
		~Dog();

		//Member functions
		void makeSound() const;
};
