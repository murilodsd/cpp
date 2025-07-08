#pragma once
#include <iostream>

template<typename T>
void printArray(T* array, int size)
{
	for(int i = 0; i < size; i++)
		std::cout << array[i] << " ";
	std::cout << std::endl;
}


template<typename T>
void add1(T& element)
{
	element++;
}

/**
 * @brief Applies a given function to each element of an array.
 *
 * This function iterates over an array and calls the provided function on each element.
 *
 * @tparam T The type of the elements in the array.
 * @tparam Func The type of the function to be applied.
 * @param array_address The address of the array to be processed.
 * @param array_length The number of elements in the array.
 * @param ptr_func The function to be called on every element of the array.
 */
template<typename T, typename Func>
void iter(T* array_address, int array_length, Func ptr_func)
{
	for (int i = 0; i < array_length; i++)
		ptr_func((array_address)[i]);
};

