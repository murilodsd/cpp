#include "Zombie.hpp"
#include <string>
#include <iostream>

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

int main()
{
    // Criando um zumbi na pilha
    std::cout << "=== Creating a zombie on the stack ===" << std::endl;
    Zombie mainZombie;
    mainZombie.set_name("mainZombie");
    mainZombie.announce();

    // Criando um zumbi no heap
    std::cout << "\n=== Creating a zombie on the heap ===" << std::endl;
    Zombie* heapZombie = newZombie("HeapZombie");
    heapZombie->announce();

    // Chamando a função randomChump para criar e anunciar um zumbi
    std::cout << "\n=== Calling randomChump to create and announce a zombie ===" << std::endl;
    randomChump("RandomZombie");

    std::cout << "\n=== Releasing the memory of the heap zombie ===" << std::endl;
    // Liberando a memória do zumbi no heap
    delete heapZombie;

    std::cout << "\n=== End of the program ===" << std::endl;
    return 0;
}
