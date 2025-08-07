#pragma once
#include <iostream>
#include <vector>
#include <iterator>

class Span
{
	private:
		std::vector<int>	_numbers;
		size_t			_max_size;

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
		template<typename Iterator>
		void addRange(Iterator start, Iterator end);
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;
};

template<typename Iterator>
void Span::addRange(Iterator start, Iterator end)
{
	size_t range = std::distance(start, end);
	size_t size_available = this->_max_size - this->_numbers.size();
	if (range > size_available)
		throw std::logic_error("There is no space to all the numbers");
	_numbers.insert(_numbers.end(), start, end);
}