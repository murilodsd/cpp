/* Embora o dynamic_cast seja a estrela deste exercício, 
é importante entender os outros operadores de cast em C++ 
para saber por que eles não são a escolha certa para este problema:

static_cast: Realiza conversões de tipo em tempo de compilação. 
É útil para conversões numéricas (como int para float) ou para navegar em uma hierarquia de classes
quando você tem certeza do tipo do objeto, pois não há verificação em tempo de execução.
Usá-lo incorretamente em um cenário polimórfico, pode levar a comportamento indefinido.

reinterpret_cast: É o tipo de cast mais perigoso.
Ele simplesmente reinterpreta a representação binária de um tipo como outro,
sem qualquer verificação de segurança. Seu uso é muito específico e geralmente deve ser evitado.

const_cast: Usado para adicionar ou remover a qualificação const (ou volatile) de uma variável.
É o único cast que pode fazer isso. */

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


