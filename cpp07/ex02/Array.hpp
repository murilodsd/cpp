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
		Array(size_t _size);

		// Copy constructor
		Array(const Array<T> &other);

		// Copy assignment operator overload
		Array<T> &operator=(const Array<T> &other);
		T& operator[](int index);
		const T& operator[](int index) const;

		// Destructor
		~Array();

		//Other methods
		size_t size() const;
};

#include "Array.tpp"
