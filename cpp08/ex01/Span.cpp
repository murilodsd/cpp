#include "Span.hpp"
#include <algorithm>
#include <stdexcept>

// ==================== Constructors ====================
Span::Span()
:
_numbers(),
_max_size(0)
{
}
Span::Span(unsigned int N)
:
_numbers(),
_max_size(N)
{
	_numbers.reserve(N);
}

// ================= Copy Constructor ==================
Span::Span(const Span &other)
:
_numbers(other._numbers),
_max_size(other._max_size)
{
}

// ========== Copy Assignment Operator Overload ==========
Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_numbers = other._numbers;
		_max_size = other._max_size;
	}
	return *this;
}

// ==================== Destructor =====================
Span::~Span()
{
}
// ================= Auxiliar Functions =================

// ================== Member Functions ==================
void Span::addNumber(int number)
{
	if (_max_size == _numbers.size())
		throw std::logic_error("Span is already full");
	_numbers.push_back(number);
}
unsigned int Span::shortestSpan() const
{
	unsigned int shortest_span;
	
	if (_numbers.size() <= 1)
		throw std::logic_error("Span size isn't enough to calculate shortest span");
	
	std::vector<int> sorted_numbers = _numbers;
    	std::sort(sorted_numbers.begin(), sorted_numbers.end());

	shortest_span = sorted_numbers[1] - sorted_numbers[0];
	for (std::vector<int>::const_iterator it = sorted_numbers.begin() + 1; it + 1 != sorted_numbers.end(); ++it)
	{
		if (static_cast<unsigned int>(*(it + 1) - *it) < shortest_span)
			shortest_span = *(it + 1) - *it;
	}
	return (shortest_span);
}

unsigned int Span::longestSpan() const
{
	if (_numbers.size() <= 1)
		throw std::logic_error("Span size isn't enough to calculate longest span");
	
	std::vector<int>::const_iterator min_it = std::min_element(_numbers.begin(), _numbers.end());
	std::vector<int>::const_iterator max_it = std::max_element(_numbers.begin(), _numbers.end());
    
	return *max_it - *min_it;
}