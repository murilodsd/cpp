/* 
Implement a Weapon class that has:
• A private attribute type, which is a string.
• A getType() member function that returns a constant reference to type.
• A setType() member function that sets type using the new value passed as a pa
rameter.
*/
#include <string>
#include "Weapon.hpp"

Weapon::Weapon(std::string type)
:
type(type)
{
}

Weapon::~Weapon()
{
}

const std::string&	Weapon::getType(void) const
{
	return (type);
}

void	Weapon::setType(const std::string &type)
{
	this->type = type;
}

