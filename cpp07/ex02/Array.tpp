#include "Array.hpp"
#include <exception>

// ==================== Constructors ====================
template<typename T>
Array<T>::Array()
:
_array(new T[0]),
_size(0)
{
}

template<typename T>

Array<T>::Array(int n)
:
_array(new T[n]),
_size(n)
{
	/* Each element is initialized using the default constructor of T (i.e., T()), ensuring
	that all elements are properly constructed even for complex types. */
	for (size_t i = 0; i < _size; i++)
		_array[i] = T();
}

// ================= Copy Constructor ==================
template<typename T>
Array<T>::Array(const Array &other)
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
		delete [] _array;
		this->_array = new T[other._size];
		this->_size = other._size;	
		for (size_t i = 0; i < other._size; i++)
			this->_array[i] = other._array[i];
	}
	return *this;
}

// ==================== Destructor =====================
template<typename T>
Array<T>::~Array()
{
	delete[] _array;
}
// ================= Auxiliar Functions =================

// ================== Member Functions ==================

template<typename T>
T &Array<T>::operator[](size_t index)
{
	if (index >= _size)
		throw std::out_of_range("Index out of range");
	return _array[index];
}

template<typename T>
const T& Array<T>::operator[](size_t index) const
{
	if (index >= _size)
		throw std::out_of_range("Index out of range");
	return _array[index];
}

template<typename T>
size_t Array<T>::size() const
{
	return (_size);
}