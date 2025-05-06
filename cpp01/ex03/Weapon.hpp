/* 
Implement a Weapon class that has:
• A private attribute type, which is a string.
• A getType() member function that returns a constant reference to type.
• A setType() member function that sets type using the new value passed as a pa
rameter.
*/
#pragma once
#include <string>

class Weapon
{
	private:
		std::string type;
	public:
		Weapon(std::string type);
		~Weapon();
		const std::string&	getType(void) const;
		void		setType(const std::string &type);
};
