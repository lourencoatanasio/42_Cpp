//
// Created by ldiogo on 1/15/24.
//

#include "../Inc/Character.hpp"

Character::Character(std::string const &name) : name(name)
{
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
}

Character::Character(const Character &character)
{
    *this = character;
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
        if (inventory[i])
            delete inventory[i];
}

Character &Character::operator=(const Character &character)
{
    name = character.name;
    for (int i = 0; i < 4; i++)
        inventory[i] = character.inventory[i];
    return (*this);
}

void Character::equip(AMateria *m)
{
    for (int i = 0; i < 4; i++)
        if (!inventory[i])
        {
            inventory[i] = m;
            return;
        }
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx > 3)
        return;
    inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
    if (idx < 0 || idx > 3 || !inventory[idx])
        return;
    inventory[idx]->use(target);
}

std::string const &Character::getName() const
{
    return (name);
}