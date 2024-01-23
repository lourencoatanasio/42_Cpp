//
// Created by ldiogo on 1/15/24.
//

#include "../Inc/Character.hpp"

Character::Character(std::string const &name) : name(name)
{
    std::cout << "Character default constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
}

Character::Character(Character const &other) : name(other.name)
{
    std::cout << "Character " << name << " copied!" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (other.inventory[i])
            inventory[i] = other.inventory[i]->clone();
        else
            inventory[i] = NULL;
    }
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
        if (inventory[i])
            delete inventory[i];
}

Character &Character::operator=(Character const &other)
{
    if (this != &other)
    {
        name = other.name;
        for (int i = 0; i < 4; i++)
        {
            if (inventory[i])
                delete inventory[i];
            if (other.inventory[i])
                inventory[i] = other.inventory[i]->clone();
            else
                inventory[i] = NULL;
        }
    }
    std::cout << "Character " << name << " copied!" << std::endl;
    return *this;
}

void Character::equip(AMateria *m)
{
    for (int i = 0; i < 4; i++)
        if (!inventory[i])
        {
            inventory[i] = m;
            return;
        }
    std::cout << "Inventory full" << std::endl;
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx > 3)
    {
        std::cout << "Invalid index" << std::endl;
        return;
    }
    inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
    if (idx < 0 || idx > 3 || !inventory[idx])
    {
        std::cout << "Invalid index" << std::endl;
        return;
    }
    inventory[idx]->use(target);
}

std::string const &Character::getName() const
{
    return (name);
}