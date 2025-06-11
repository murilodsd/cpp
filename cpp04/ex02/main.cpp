#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() {
    std::cout << "=== CPP04 EX02 - Abstract Animal, Deep Copy, WrongAnimal Test ===" << std::endl;
    
    // Test 0: Demonstrate Animal is abstract (cannot be instantiated)
    std::cout << "\n--- Test 0: Animal is Abstract ---" << std::endl;
    //Animal animal;
    std::cout << "// Animal animal; // <- COMPILATION ERROR: Cannot instantiate abstract class" << std::endl;
    std::cout << "// Animal* ptr = new Animal(); // <- COMPILATION ERROR" << std::endl;
    std::cout << "// Animal animals[10]; <- COMPILATION ERROR" << std::endl;
    std::cout << "Only pointers to derived classes (Dog*, Cat*) can be stored in Animal*" << std::endl;
    std::cout << "Animal class is abstract because makeSound() is pure virtual (= 0)" << std::endl;
    
    // Test 1: Basic polymorphic array
    std::cout << "\n--- Test 1: Polymorphic Array ---" << std::endl;
    const int N = 6;
    Animal* animals[N];
    
    for (int i = 0; i < N; ++i) {
        if (i % 2 == 0) {
            std::cout << "Creating Dog " << i/2 + 1 << std::endl;
            animals[i] = new Dog();
        } else {
            std::cout << "Creating Cat " << i/2 + 1 << std::endl;
            animals[i] = new Cat();
        }
    }
    
    std::cout << "\n--- Animal Sounds ---" << std::endl;
    for (int i = 0; i < N; ++i) {
        std::cout << animals[i]->getType() << " says: ";
        animals[i]->makeSound();
    }
    
    std::cout << "\n--- Cleaning up array ---" << std::endl;
    for (int i = 0; i < N; ++i) {
        std::cout << "Deleting " << animals[i]->getType() << std::endl;
        delete animals[i];
    }
    
    // Test 2: Deep Copy with Cat
    std::cout << "\n--- Test 2: Deep Copy (Cat) ---" << std::endl;
    Cat originalCat;
    originalCat.getBrain()->setIdea(0, "Fish are delicious");
    originalCat.getBrain()->setIdea(1, "I love sleeping");
    originalCat.getBrain()->setIdea(2, "Boxes are comfortable");
    
    std::cout << "Original cat ideas:" << std::endl;
    for (int i = 0; i < 3; ++i) {
        std::cout << "  Idea " << i << ": " << originalCat.getBrain()->getIdea(i) << std::endl;
    }
    
    Cat copiedCat = originalCat; // Copy constructor
    std::cout << "\nAfter copy constructor, copied cat ideas:" << std::endl;
    for (int i = 0; i < 3; ++i) {
        std::cout << "  Idea " << i << ": " << copiedCat.getBrain()->getIdea(i) << std::endl;
    }
    
    // Modify copied cat's brain
    copiedCat.getBrain()->setIdea(0, "Dogs are weird");
    copiedCat.getBrain()->setIdea(1, "I want to play");
    
    std::cout << "\nAfter modifying copied cat:" << std::endl;
    std::cout << "Original cat idea 0: " << originalCat.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copied cat idea 0: " << copiedCat.getBrain()->getIdea(0) << std::endl;
    std::cout << "Original cat idea 1: " << originalCat.getBrain()->getIdea(1) << std::endl;
    std::cout << "Copied cat idea 1: " << copiedCat.getBrain()->getIdea(1) << std::endl;
    
    // Test 3: Assignment operator with Dog
    std::cout << "\n--- Test 3: Assignment Operator (Dog) ---" << std::endl;
    Dog dog1;
    dog1.getBrain()->setIdea(0, "Chase cats!");
    dog1.getBrain()->setIdea(1, "Fetch the ball");
    
    Dog dog2;
    dog2.getBrain()->setIdea(0, "Bark at mailman");
    
    std::cout << "Before assignment:" << std::endl;
    std::cout << "Dog1 idea 0: " << dog1.getBrain()->getIdea(0) << std::endl;
    std::cout << "Dog2 idea 0: " << dog2.getBrain()->getIdea(0) << std::endl;
    
    dog2 = dog1; // Assignment operator
    
    std::cout << "\nAfter assignment (dog2 = dog1):" << std::endl;
    std::cout << "Dog1 idea 0: " << dog1.getBrain()->getIdea(0) << std::endl;
    std::cout << "Dog2 idea 0: " << dog2.getBrain()->getIdea(0) << std::endl;
    
    // Modify dog2 to prove deep copy
    dog2.getBrain()->setIdea(0, "Eat treats!");
    
    std::cout << "\nAfter modifying dog2:" << std::endl;
    std::cout << "Dog1 idea 0: " << dog1.getBrain()->getIdea(0) << std::endl;
    std::cout << "Dog2 idea 0: " << dog2.getBrain()->getIdea(0) << std::endl;
    
    std::cout << "\n=== All tests completed successfully! ===" << std::endl;
    return 0;
}