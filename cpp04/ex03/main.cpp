#include <iostream>
#include <string>
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
    std::cout << "=== CPP04 EX03 - MATERIA SYSTEM TEST ===" << std::endl;

    // Test 1: Basic MateriaSource functionality
    std::cout << "\n--- Test 1: MateriaSource Creation and Learning ---" << std::endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    
    std::cout << "\n--- Test 1.1: Creating materias from learned types ---" << std::endl;
    AMateria* tmp;
    tmp = src->createMateria("ice");
    std::cout << "Created materia type: " << (tmp ? tmp->getType() : "NULL") << std::endl;
    delete tmp;
    
    tmp = src->createMateria("cure");
    std::cout << "Created materia type: " << (tmp ? tmp->getType() : "NULL") << std::endl;
    delete tmp;
    
    tmp = src->createMateria("fire"); // Unknown type
    std::cout << "Created unknown materia: " << (tmp ? "SUCCESS" : "NULL (expected)") << std::endl;

    // Test 2: Character creation and basic operations
    std::cout << "\n--- Test 2: Character Creation and Equipment ---" << std::endl;
    ICharacter* me = new Character("me");
    std::cout << "Character created with name: " << me->getName() << std::endl;

    // Test 3: Equipping materias
    std::cout << "\n--- Test 3: Equipping Materias ---" << std::endl;
    AMateria* ice1 = src->createMateria("ice");
    AMateria* cure1 = src->createMateria("cure");
    AMateria* ice2 = src->createMateria("ice");
    AMateria* cure2 = src->createMateria("cure");
    
    me->equip(ice1);
    me->equip(cure1);
    me->equip(ice2);
    me->equip(cure2);
    
    // Try to equip 5th materia (should fail)
    std::cout << "\n--- Test 3.1: Trying to equip 5th materia (should fail) ---" << std::endl;
    AMateria* extraIce = src->createMateria("ice");
    me->equip(extraIce);
    delete extraIce; // Clean up since it wasn't equipped

    // Test 4: Using materias
    std::cout << "\n--- Test 4: Using Materias ---" << std::endl;
    ICharacter* bob = new Character("bob");
    
    me->use(0, *bob); // ice
    me->use(1, *bob); // cure
    me->use(2, *bob); // ice
    me->use(3, *bob); // cure
    me->use(4, *bob); // invalid slot

    // Test 5: Unequipping materias
    std::cout << "\n--- Test 5: Unequipping Materias ---" << std::endl;
    me->unequip(0); // Should go to dropped materias
    me->unequip(1); // Should go to dropped materias
    me->unequip(0); // Should fail (already unequipped)
    me->unequip(5); // Should fail (invalid slot)

    // Test 6: Using after unequip
    std::cout << "\n--- Test 6: Using Materias After Unequip ---" << std::endl;
    me->use(0, *bob); // Should fail (unequipped)
    me->use(2, *bob); // Should work (still equipped)

    // Test 7: Re-equipping
    std::cout << "\n--- Test 7: Re-equipping New Materias ---" << std::endl;
    AMateria* newIce = src->createMateria("ice");
    AMateria* newCure = src->createMateria("cure");
    me->equip(newIce);
    me->equip(newCure);
    
    me->use(0, *bob); // Should work with new materia
    me->use(1, *bob); // Should work with new materia

    // Test 8: Copy constructor and assignment operator
    std::cout << "\n--- Test 8: Character Copy Constructor ---" << std::endl;
    Character original("original");
    original.equip(src->createMateria("ice"));
    original.equip(src->createMateria("cure"));
    
    Character copied = original; // Copy constructor
    std::cout << "Original character name: " << original.getName() << std::endl;
    std::cout << "Copied character name: " << copied.getName() << std::endl;
    
    std::cout << "\n--- Test 8.1: Using materias from both characters ---" << std::endl;
    original.use(0, *bob);
    copied.use(0, *bob);
    
    std::cout << "\n--- Test 8.2: Character Assignment Operator ---" << std::endl;
    Character assigned("assigned");
    assigned = original; // Assignment operator
    std::cout << "Assigned character name: " << assigned.getName() << std::endl;
    assigned.use(0, *bob);

    // Test 9: MateriaSource copy operations
    std::cout << "\n--- Test 9: MateriaSource Copy Operations ---" << std::endl;
    MateriaSource* srcCopy = new MateriaSource(*static_cast<MateriaSource*>(src));
    AMateria* copyIce = srcCopy->createMateria("ice");
    AMateria* copyCure = srcCopy->createMateria("cure");
    
    std::cout << "Materia from copied source: " << (copyIce ? copyIce->getType() : "NULL") << std::endl;
    std::cout << "Materia from copied source: " << (copyCure ? copyCure->getType() : "NULL") << std::endl;
    
    delete copyIce;
    delete copyCure;

    // Test 10: Memory leak prevention
    std::cout << "\n--- Test 10: Testing MateriaSource Full Inventory ---" << std::endl;
    src->learnMateria(new Ice()); // 3rd materia
    src->learnMateria(new Cure()); // 4th materia
    src->learnMateria(new Ice()); // 5th materia (should be deleted automatically)

    // Clean up
    std::cout << "\n--- Cleanup Phase ---" << std::endl;
    delete bob;
    delete me;
    delete src;
    delete srcCopy;
    
    // Test 11: Cleanup dropped materias
    std::cout << "\n--- Test 11: Cleaning Up Dropped Materias ---" << std::endl;
    AMateria::cleanupDroppedMaterias();
    
    std::cout << "\n=== ALL TESTS COMPLETED ===" << std::endl;
    return 0;
}
 /* 
int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	return 0;
} */