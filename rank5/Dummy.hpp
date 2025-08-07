#pragma once
#include <string>
#include <ATarget.hpp>

class Dummy : public ATarget
{
	private:		
		Dummy(const Dummy& other);		
		Dummy& operator=(const Dummy& other);
	
	public:
		Dummy();		
		~Dummy();
		Dummy* clone() const;
};
