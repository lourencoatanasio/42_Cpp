//
// Created by ldiogo on 22//2024.
//

#include"../Inc/interfaces.hpp"

int main()
{
    // create sources for materia concrete classes Ice and Cure
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    std::cout << std::endl;

    // create a character and equip him with materia
    ICharacter* me = new Character("me");
    AMateria *tmp;
    tmp = src->createMateria("ice"); me->equip(tmp);
    AMateria *tmp2 = tmp;
    tmp = src->createMateria("cure"); me->equip(tmp);
    std::cout << std::endl;

    // create another character as a target

    ICharacter* bob = new Character("bob");
    std::cout << "me: "; me->use(0, *bob);
    std::cout << "me: "; me->use(1, *bob);
    std::cout << std::endl;

    // unequip, delete and test use() again
    std::cout << "unequip, delete materia and test use() again." << std::endl;
    me->unequip(0);
    delete tmp2;
    me->use(0, *bob);
    me->use(1, *bob);
    std::cout << std::endl;

    // use and unequip out of range
    std::cout << "use and unequip out of range." << std::endl;
    me->use(10, *bob);
    me->unequip(10);
    std::cout << std::endl;

    // equip too many materia
    std::cout << "equip too many materia." << std::endl;
    for (int i = 0; i <= 3; i++)
    {
        tmp = src->createMateria("ice");
        me->equip(tmp);
    }
    delete tmp;
    std::cout << std::endl;

    // deep copy
    Character *original = new Character("original");
    {
        IMateriaSource* src1 = new MateriaSource();
        src1->learnMateria(new Ice());
        AMateria *tmp1;
        tmp1 = src1->createMateria("ice"); original->equip(tmp1);
        Character copy = *original;
        delete original;
        copy.use(0, *bob);
        delete src1;
    }
    std::cout << std::endl;

    // deep copy
    original = new Character("original");
    {
        IMateriaSource* src1 = new MateriaSource();
        src1->learnMateria(new Ice());
        AMateria *tmp1;
        tmp1 = src1->createMateria("ice"); original->equip(tmp1);
        Character copy(*original);
        delete original;
        copy.use(0, *bob);
        delete src1;
    }
    std::cout << std::endl;

    // delete all the allocated memory
    delete bob;
    delete me;
    delete src;
    return 0;
}