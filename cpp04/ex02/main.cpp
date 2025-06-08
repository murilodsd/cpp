#include "AAnimal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include <iostream>
#include <cstdlib>

int main()
{
    std::cout << "===== ANIMAL TESTS =====" << std::endl;

    std::cout << "\n[1] Creating Animal, Dog, and Cat objects using Animal pointers..." << std::endl;
    //const AAnimal* animal = new AAnimal();
    const AAnimal* dog = new Dog();
    const AAnimal* cat = new Cat();

    std::cout << "\n[2] Checking types using getType():" << std::endl;
    std::cout << "  - dog->getType(): " << dog->getType() << std::endl;
    std::cout << "  - cat->getType(): " << cat->getType() << std::endl;
    //std::cout << "  - animal->getType(): " << animal->getType() << std::endl;

    std::cout << "\n[3] Calling makeSound() on each pointer:" << std::endl;
    std::cout << "  - cat->makeSound(): ";
    cat->makeSound();
    std::cout << "  - dog->makeSound(): ";
    dog->makeSound();
//     std::cout << "  - animal->makeSound(): ";
//     animal->makeSound();

    std::cout << "\n[4] Deleting Animal, Dog, and Cat objects..." << std::endl;
    //delete animal;
    delete dog;
    delete cat;

    std::cout << "\n===== WRONG ANIMAL TESTS =====" << std::endl;

    std::cout << "\n[5] Creating WrongAnimal and WrongCat objects using WrongAnimal pointers..." << std::endl;
    const WrongAnimal* wrong_animal = new WrongAnimal();
    const WrongAnimal* wrong_cat = new WrongCat();

    std::cout << "\n[6] Checking type of wrong_cat using getType():" << std::endl;
    std::cout << "  - wrong_cat->getType(): " << wrong_cat->getType() << std::endl;

    std::cout << "\n[7] Calling makeSound() on each WrongAnimal pointer:" << std::endl;
    std::cout << "  - wrong_cat->makeSound(): ";
    wrong_cat->makeSound();
    std::cout << "  - wrong_animal->makeSound(): ";
    wrong_animal->makeSound();

    std::cout << "\n[8] Deleting WrongAnimal and WrongCat objects..." << std::endl;
    delete wrong_animal;
    delete wrong_cat;

    std::cout << "\n===== END OF TESTS =====" << std::endl;

    return (EXIT_SUCCESS);
}