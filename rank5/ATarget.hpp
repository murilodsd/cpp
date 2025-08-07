#pragma once
#include <string>
#include <ASpell.hpp>

class ATarget
{
	private:
		std::string type;		
		ATarget() {};		
		ATarget(const ATarget& other);		
		ATarget& operator=(const ATarget& other);
		
	public:
	
		ATarget(const std::string& type);
		const	std::string& getType() const;
		virtual ATarget* clone() const = 0;
		void getHitBySpell(const ASpell& spell) const;

		~ATarget();
};
