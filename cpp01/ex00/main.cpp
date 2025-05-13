#include "Zombie.hpp"
#include <string>
#include <iostream>
#include <cstdlib>

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

int main()
{
    std::cout << "=== Creating a zombie on the stack ===" << std::endl;
    Zombie mainZombie;
    mainZombie.set_name("mainZombie");
    mainZombie.announce();

    std::cout << "\n=== Creating a zombie on the heap ===" << std::endl;
    Zombie* heapZombie = newZombie("HeapZombie");
    heapZombie->announce();

    std::cout << "\n=== Calling randomChump to create and announce a zombie ===" << std::endl;
    randomChump("RandomZombie");

    std::cout << "\n=== Releasing the memory of the heap zombie ===" << std::endl;
    delete heapZombie;

    std::cout << "\n=== End of the program ===" << std::endl;
    return (EXIT_SUCCESS);
}
