#pragma once
#include <iostream>
#include <stack>
#include <deque>

template<typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public:
		typedef typename Container::iterator			iterator;
		typedef typename Container::const_iterator		const_iterator;
		typedef typename Container::reverse_iterator		reverse_iterator;
		typedef typename Container::const_reverse_iterator	const_reverse_iterator;

		// Default constructor
		MutantStack();

		// Copy constructor
		MutantStack(const MutantStack &other);

		// Copy assignment operator overload
		MutantStack &operator=(const MutantStack &other);

		// Destructor
		~MutantStack();


		// Others methods

		iterator 		begin();
		const_iterator		begin() const;
		reverse_iterator	rbegin();
		const_reverse_iterator	rbegin() const;
		iterator 		end();
		const_iterator		end() const;
		reverse_iterator 	rend();
		const_reverse_iterator 	rend() const;
		
		void			print();
		void			reverse_print();
};

// ==================== Constructors ====================
template<typename T, typename Container>
MutantStack<T, Container>::MutantStack()
:
std::stack<T, Container>()
{
}

// ================= Copy Constructor ==================
template<typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack<T, Container> &other)
:
std::stack<T, Container>(other)
{
}

// ========== Copy Assignment Operator Overload ==========
template<typename T, typename Container>
MutantStack<T, Container> &MutantStack<T, Container>::operator=(const MutantStack<T, Container> &other)
{
	if (this != &other)
	{
		std::stack<T, Container>::operator=(other);
	}
	return *this;
}

// ==================== Destructor =====================
template<typename T, typename Container>
MutantStack<T, Container>::~MutantStack()
{
}
// ================= Auxiliar Functions =================

// ================== Member Functions ==================
template<typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin()
{
	return this->c.begin();
}

template<typename T, typename Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::begin() const
{
	return this->c.begin();
}

template<typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::rbegin()
{
	return this->c.rbegin();
}

template<typename T, typename Container>
typename MutantStack<T, Container>::const_reverse_iterator MutantStack<T, Container>::rbegin() const
{
	return this->c.rbegin();
}

template<typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end()
{
	return this->c.end();
}

template<typename T, typename Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::end() const
{
	return this->c.end();
}

template<typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::rend()
{
	return this->c.rend();
}

template<typename T, typename Container>
typename MutantStack<T, Container>::const_reverse_iterator MutantStack<T, Container>::rend() const
{
	return this->c.rend();
}

template<typename T, typename Container>
void MutantStack<T, Container>::print()
{
	for (typename MutantStack<T, Container>::iterator it = this->begin(); it != this->end(); ++it)
	{
		if (it != this->begin())
			std::cout << ", ";
		std::cout << *it;
	}
	std::cout << std::endl;
}

template<typename T, typename Container>
void MutantStack<T, Container>::reverse_print()
{
	for (typename MutantStack<T, Container>::reverse_iterator it = this->rbegin(); it != this->rend(); ++it)
	{
		if (it != this->rbegin())
			std::cout << ", ";
		std::cout << *it;
	}
	std::cout << std::endl;
}