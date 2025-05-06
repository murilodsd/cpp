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
#pragma once
#include <string>
#include "Weapon.hpp"

// Define colors for terminal output
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

class HumanB
{
	private:
		std::string name;
		Weapon *weapon;
	public:
		HumanB(std::string name);
		~HumanB();
		void	attack();
		void	setWeapon(Weapon &weapon);
};
