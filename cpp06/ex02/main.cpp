/* Although dynamic_cast is the star of this exercise,
it's important to understand the other cast operators in C++
to know why they are not the right choice for this problem:

static_cast: Performs type conversions at compile time.
It's useful for numeric conversions (like int to float) or for navigating a class hierarchy
when you are certain of the object's type, as there is no runtime checking.
Using it incorrectly in a polymorphic scenario can lead to undefined behavior.

reinterpret_cast: This is the most dangerous type of cast.
It simply reinterprets the binary representation of one type as another,
without any safety checks. Its use is very specific and should generally be avoided.

const_cast: Used to add or remove const (or volatile) qualification from a variable.
It's the only cast that can do this. */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "functions.hpp"
#include <cstdlib>

int main()
{
	srand(time(NULL));
	std::cout << "=== C++ 06 - Exercise 02: Real Type Identification ===" << std::endl;
	std::cout << std::endl;

	// Creating instances of derived classes randomly
	std::cout << "Creating instances randomly..." << std::endl;
	Base* a = generate(); // Randomly generates A, B, or C
	Base* b = generate();
	Base* c = generate();
	
	std::cout << std::endl;
	std::cout << "Testing identify function with pointers (random objects):" << std::endl;
	std::cout << "Object 1: ";
	identify(a);
	std::cout << "Object 2: ";
	identify(b);
	std::cout << "Object 3: ";
	identify(c);
	
	std::cout << std::endl;
	std::cout << "Testing identify function with references (random objects):" << std::endl;
	std::cout << "Object 1: ";
	identify(*a);
	std::cout << "Object 2: ";
	identify(*b);
	std::cout << "Object 3: ";
	identify(*c);
	
	// Creating specific instances directly
	std::cout << std::endl;
	std::cout << "Creating specific instances (A, B, C)..." << std::endl;
	Base* objA = new A();
	Base* objB = new B();
	Base* objC = new C();
	
	std::cout << std::endl;
	std::cout << "Testing identify function with pointers (specific objects):" << std::endl;
	std::cout << "Object A: ";
	identify(objA);
	std::cout << "Object B: ";
	identify(objB);
	std::cout << "Object C: ";
	identify(objC);
	
	std::cout << std::endl;
	std::cout << "Testing identify function with references (specific objects):" << std::endl;
	std::cout << "Object A: ";
	identify(*objA);
	std::cout << "Object B: ";
	identify(*objB);
	std::cout << "Object C: ";
	identify(*objC);
	
	std::cout << std::endl;
	std::cout << "Cleaning up memory..." << std::endl;
	delete a;
	delete b;
	delete c;
	delete objA;
	delete objB;
	delete objC;
	
	std::cout << "Test completed successfully!" << std::endl;
	return 0;
}


