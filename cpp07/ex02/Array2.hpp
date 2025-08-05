#pragma once
#include <iostream>

template<typename T>
class Array
{
	private:
		T* _array;
		size_t _size;
	public:
		// Default constructor
		Array();
		Array(size_t _size);

		// Copy constructor
		Array(const Array &other);

		// Copy assignment operator overload
		Array &operator=(const Array &other);

		// Destructor
		~Array();

		T& operator[](unsigned int index);
		const size_t& size() const;
};

#include <exception>
#include <stdexcept>

// ==================== Constructors ====================
template<typename T>
Array<T>::Array()
:
_array(new T[0]),
_size(0)
{
}

template<typename T>
Array<T>::Array(size_t size)
:
_array(new T[size]),
_size(size)
{
	for (size_t i = 0; i < _size; i++)
		_array[i] = T();
}

// ================= Copy Constructor ==================
template<typename T>
Array<T>::Array(const Array<T> &other)
:
_array(new T[other._size]),
_size(other._size)
{
	for (size_t i = 0; i < _size; i++)
		this->_array[i] = other._array[i];
}

// ========== Copy Assignment Operator Overload ==========
template<typename T>
Array<T> &Array<T>::operator=(const Array<T> &other)
{
	if (this != &other)
	{
		delete[] this->_array;
		this->_size = other._size;
		this->_array = new T[this->_size];
		for (size_t i = 0; i < _size; i++)
			this->_array[i] = other._array[i];
	}
	return *this;
}

// ==================== Destructor =====================
template<typename T>
Array<T>::~Array()
{
	delete[] this->_array;
}
// ================= Auxiliar Functions =================

template<typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw std::out_of_range("Index out of bounds");
	return this->_array[index];
}

// ================== Member Functions ==================
template<typename T>
const size_t& Array<T>::size() const
{
	return _size;
}