#include "FragTrap.hpp"
#include <iostream>
#include <cstdlib>

int main() {
    FragTrap a("Alpha");
    FragTrap b("Bravo");

    std::cout << "\n=== Initial attacks ===" << std::endl;
    a.attack("Bravo");
    b.attack("Alpha");
    
    std::cout << "\n=== Simulating damage ===" << std::endl;
    b.takeDamage(5);
    a.takeDamage(3);

    std::cout << "\n=== Repairs ===" << std::endl;
    a.beRepaired(2);
    b.beRepaired(4);

    std::cout << "\n=== Attack until energy runs out ===" << std::endl;
    for (int i = 0; i < 100; ++i) {
        a.attack("Bravo");
    }

    std::cout << "\n=== Attempt to repair with no energy ===" << std::endl;
    a.beRepaired(5);

    std::cout << "\n=== Bravo receives fatal damage ===" << std::endl;
    b.takeDamage(100);

    std::cout << "\n=== Attempt to attack and repair with no hit points ===" << std::endl;
    b.attack("Alpha");
    b.beRepaired(10);

    std::cout << "\n=== Self-assignment and copy test ===" << std::endl;
    FragTrap c = a; // Copy constructor
    c.attack("Bravo");

    std::cout << "\n=== Assignment operator test ===" << std::endl;
    FragTrap d("Delta");
    d = a;
    d.attack("Bravo");

    std::cout << "\n=== Testing Member Function highFivesGuys ===" << std::endl;
    a.highFivesGuys();

    return (EXIT_SUCCESS);
}