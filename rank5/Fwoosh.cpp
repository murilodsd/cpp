#pragma once
#include "Fwoosh.hpp"
#include "ASpell.hpp"

Fwoosh::Fwoosh()
:
ASpell("Fwoosh", "fwooshed")
{
}

Fwoosh::Fwoosh(const Fwoosh& other)
:
ASpell(other.getName(), other.getEffects())
{
}
	
Fwoosh& Fwoosh::operator=(const Fwoosh& other)
{
	return *this;
}

Fwoosh::~Fwoosh()
{
}

Fwoosh* Fwoosh::clone() const
{
	Fwoosh *cpyFwoosh = new Fwoosh(*this);
	return cpyFwoosh;
}

