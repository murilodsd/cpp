#include <cstdlib>
#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <exception>

/* It randomly instantiates A, B, or C and returns the instance as a Base pointer. Feel free
to use anything you like for the random choice implementation. */
Base * generate(void)
{
	int random_num = rand() % 3;

	switch (random_num)
	{
		case 0:
			std::cout << "Generated an object of class A" << std::endl;
			return (new A());
		case 1:
			std::cout << "Generated an object of class B" << std::endl;
			return (new B());
		default:
			std::cout << "Generated an object of class C" << std::endl;
			return (new C());
	}
}


/* It prints the actual type of the object pointed to by p: "A", "B", or "C". */
void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "The actual type of the object pointed to is A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "The actual type of the object pointed to is B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "The actual type of the object pointed to is C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

/* It prints the actual type of the object referenced by p: "A", "B", or "C". Using a pointer
  inside this function is forbidden. */
void identify(Base& p)
{
	try
	{
		A& ref_A = dynamic_cast<A&>(p);
		(void)ref_A;
		std::cout << "The actual type of the object referred to is A" << std::endl;
	}
	catch(const std::exception& e)
	{
		try
		{
			B& ref_B = dynamic_cast<B&>(p);
			(void)ref_B;
			std::cout << "The actual type of the object referred to is B" << std::endl;
		}
		catch(const std::exception& e)
		{
			try
			{
				C& ref_C = dynamic_cast<C&>(p);
				(void)ref_C;
				std::cout << "The actual type of the object referred to is C" << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cerr << "Failed to convert: " << e.what() << '\n';
			}
		}
	}
}