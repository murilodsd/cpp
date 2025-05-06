/* 
Now, create two classes: HumanA and HumanB. They both have a Weapon and
a name. They also have a member function attack() that displays (without the angle
brackets):
<name> attacks with their <weapon type>
HumanA and HumanB are almost identical except for these two small details:
• While HumanA takes the Weapon in its constructor, HumanB does not.
• HumanB may not always have a weapon, whereas HumanA will always be
armed 
*/
#include <string>
#include <iostream>
#include "Weapon.hpp"
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon)
:
name(name),
weapon(weapon)
{
};

HumanA::~HumanA()
{
};

void	HumanA::attack()
{
	std::cout << CYAN << name << " attacks with their " << weapon.getType() << RESET << std::endl;
};
