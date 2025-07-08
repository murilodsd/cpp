#pragma once
#include <iostream>

template<typename T>
class Array
{
	private:
		T*		_array;
		size_t		_size;

	public:
		// Default constructor
		Array();
		Array(int n);

		// Copy constructor
		Array(const Array<T> &other);

		// Copy assignment operator overload
		Array<T> &operator=(const Array<T> &other);
		T& operator[](size_t index);
		const T& operator[](size_t index) const;

		// Destructor
		~Array();

		//Other methods
		size_t size() const;
};

#include "Array.tpp"
