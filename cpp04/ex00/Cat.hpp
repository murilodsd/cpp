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

class Cat : public Animal
{
	public:
		// Default constructor
		Cat();

		// Copy constructor
		Cat(const Cat &other);

		// Copy assignment operator overload
		Cat &operator=(const Cat &other);

		// Destructor
		~Cat();

		//Member functions
		void makeSound() const;
};
