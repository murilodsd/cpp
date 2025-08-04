#include "iter.hpp"
#include <string>
#include <iostream>
#include <cctype>

/*
Subject: Function Templates applied to arrays and function pointers.

Objective: This exercise raises the level of abstraction.
The goal is to create a function template called iter that executes a given function on each element of an array.

The iter function must accept three arguments:

- The address of an array.
- The size (length) of the array.
- A pointer to a function that will be called for each element of the array.

The purpose is to demonstrate the power of templates to create generic algorithms.
You learn to combine templates with function pointers to apply any operation to a collection of data of any type.
This exercise is a precursor to understanding how STL (Standard Template Library) algorithms work,
such as std::for_each.
*/

void	toupperstring(std::string& str)
{
	for(unsigned int i = 0; i < str.length(); i++)
		str[i] = toupper(str[i]);
}

template<typename T>
void print(const T& x) {
    std::cout << x << " ";
}

int main()
{
	int array_number[6] = {0, 1, 2, 3, 4, 5};
	char array_char[6] = {'0', '1', '2', '3', '4', '5'};
	std::string array_string[6] = {"zero", "um", "dois", "tres", "quatro", "cinco"};
	const int const_array_number[6] = {10, 11, 12, 13, 14, 15};
	size_t size = 6;

	std::cout << "Original integer array: ";
	printArray(array_number, size);

	iter(array_number, size, add1<int>);
	std::cout << "Integer array after add1: ";
	printArray(array_number, size);

	std::cout << "Original char array: ";
	printArray(array_char, size);

	iter(array_char, size, add1<char>);
	std::cout << "Char array after add1: ";
	printArray(array_char, size);

	std::cout << "Original string array: ";
	printArray(array_string, size);

	iter(array_string, size, toupperstring);
	std::cout << "String array after toupperstring: ";
	printArray(array_string, size);

	std::cout << "\n--- Testing with a const array ---" << std::endl;
	std::cout << "Original const int array: ";
	printArray(const_array_number, size);
	std::cout << "Printing const array using iter: ";
	iter(const_array_number, size, print<int>);
	std::cout << std::endl;

	return 0;
}
