#include <cstdlib>
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
			return (new A());
		case 1:
			return (new B());
		default:
			return (new C());
	}
}


/* It prints the actual type of the object pointed to by p: "A", "B", or "C". */
 void identify(Base* p)
 {
	A* ptr_A = dynamic_cast<A*>(p);
	B* ptr_B = dynamic_cast<B*>(p);
	C* ptr_C = dynamic_cast<C*>(p);

	if (ptr_A != NULL)
		std::cout << "The actual type of the object pointed to is A" << std::endl;
	else if (ptr_B != NULL)
		std::cout << "The actual type of the object pointed to is B" << std::endl;
	else if (ptr_C != NULL)
		std::cout << "The actual type of the object pointed to is C" << std::endl;
 }

/* It prints the actual type of the object referenced by p: "A", "B", or "C". Using a pointer
  inside this function is forbidden. */
void identify(Base& p)
{
	try
	{
		A& ref_A = dynamic_cast<A&>(p);
		(void)ref_A;
		std::cout << "The actual type of the object refered to is A" << std::endl;
	}
	catch(const std::exception& e)
	{
		try
		{
			B& ref_B = dynamic_cast<B&>(p);
			(void)ref_B;
			std::cout << "The actual type of the object refered to is B" << std::endl;
		}
		catch(const std::exception& e)
		{
			try
			{
				C& ref_C = dynamic_cast<C&>(p);
				(void)ref_C;
				std::cout << "The actual type of the object refered to is C" << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cerr << "Failed to convert: " << e.what() << '\n';
			}
			
		}
		
	}
	
}