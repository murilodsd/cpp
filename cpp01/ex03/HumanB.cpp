/* 
Now, create two classes: HumanB and HumanB. They both have a Weapon and
a name. They also have a member function attack() that displays (without the angle
brackets):
<name> attacks with their <weapon type>
HumanB and HumanB are almost identical except for these two small details:
• While HumanB takes the Weapon in its constructor, HumanB does not.
• HumanB may not always have a weapon, whereas HumanB will always be
armed 
*/
#include <string>
#include <iostream>
#include "Weapon.hpp"
#include "HumanB.hpp"

HumanB::HumanB(std::string name)
:
name(name),
weapon(NULL)
{
};

HumanB::~HumanB()
{
};

void	HumanB::attack()
{
	std::cout << CYAN << name << " attacks with their " << weapon->getType() << RESET << std::endl;
};

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}
