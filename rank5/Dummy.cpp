#include "Dummy.hpp"
#include <iostream>

Dummy::Dummy()
:
ATarget("Target Practice Dummy")
{
}

Dummy::Dummy(const Dummy& other)
:
ATarget(other.getType())
{
}
	
Dummy& Dummy::operator=(const Dummy& other)
{
	return *this;
}

Dummy::~Dummy()
{
}

Dummy* Dummy::clone() const
{
	Dummy* newDummy = new Dummy(*this);
	return (newDummy);
}
