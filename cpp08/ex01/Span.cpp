#include "Span.hpp"
#include <algorithm>
#include <stdexcept>

// ==================== Constructors ====================
Span::Span()
:
_numbers(),
_size(0)
{
}
Span::Span(unsigned int N)
:
_numbers(),
_size(N)
{
	_numbers.reserve(N);
}

// ================= Copy Constructor ==================
Span::Span(const Span &other)
:
_numbers(other._numbers),
_size(other._size)
{
}

// ========== Copy Assignment Operator Overload ==========
Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_numbers = other._numbers;
		_size = other._size;
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
	if (_size == _numbers.size())
		throw std::logic_error("Span is already full");
	_numbers.push_back(number);
	std::sort(_numbers.begin(), _numbers.end());
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	for (std::vector<int>::iterator it = begin; it != end; ++it)
		addNumber(*it);
}
unsigned int Span::shortestSpan() const
{
	unsigned int shortest_span ;
	if (_numbers.size() <= 1)
		throw std::logic_error("Span size isn't enough to calculate shortest span");
	shortest_span = abs(*_numbers.begin() - *(_numbers.begin() + 1));
	for (std::vector<int>::const_iterator it = _numbers.begin() + 1; it + 1 != _numbers.end(); ++it)
	{
		if (abs(*it - *(it + 1)) < shortest_span)
			shortest_span = static_cast<unsigned int>(abs(*it - *(it + 1)));
	}
	return (shortest_span);
}

unsigned int Span::longestSpan() const
{
	unsigned int longest_span ;
	if (_numbers.size() <= 1)
		throw std::logic_error("Span size isn't enough to calculate longest span");
	longest_span = static_cast<unsigned int>(abs(*_numbers.begin() - *(_numbers.end() - 1)));
	return (longest_span);
}