#include "Span.hpp"
#include <algorithm>
#include <stdexcept>
#include <climits> // Para UINT_MAX

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
	if (_numbers.size() <= 1)
		throw std::logic_error("Span size isn't enough to calculate shortest span");
	
	std::vector<int> sorted_numbers = _numbers;
	std::sort(sorted_numbers.begin(), sorted_numbers.end());

	unsigned int shortest_span = UINT_MAX;

	for (size_t i = 1; i < sorted_numbers.size(); ++i)
	{
		unsigned int current_span = sorted_numbers[i] - sorted_numbers[i - 1];
		if (current_span < shortest_span)
			shortest_span = current_span;
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