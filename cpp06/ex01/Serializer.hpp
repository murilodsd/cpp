#pragma once
#include <iostream>
#include "data.hpp"
#include <stdint.h>

class Serializer
{
	private:
		// Default constructor
		Serializer();

		// Copy constructor
		Serializer(const Serializer &other);

		// Copy assignment operator overload
		Serializer &operator=(const Serializer &other);

		// Destructor
		~Serializer();

	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};
