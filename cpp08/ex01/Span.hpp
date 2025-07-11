#pragma once
#include <iostream>
#include <vector>
#include <cmath>

class Span
{
	private:
	std::vector<int>	_numbers;
	size_t			_size;

	public:
		// Default constructor
		Span();
		Span(unsigned int N);

		// Copy constructor
		Span(const Span &other);

		// Copy assignment operator overload
		Span &operator=(const Span &other);

		// Destructor
		~Span();

		//others methods
		void addNumber(int number);
		void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;
};
