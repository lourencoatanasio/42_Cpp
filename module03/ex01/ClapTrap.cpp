//
// Created by ldiogo on 1/12/24.
//

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string &name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap " << name << " created" << std::endl;
}

ClapTrap :: ClapTrap()
{
    this->name = "ClapTrap";
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;
    std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << name << " destroyed" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
    if(this->hitPoints <= 0)
    {
        std::cout << "ClapTrap " << name << " is dead!" << std::endl;
        return;
    }
    if(this->energyPoints == 0)
    {
        std::cout << "ClapTrap " << name << " has no energy points left!" << std::endl;
        return;
    }
    this->energyPoints -= 1;
    std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    this->hitPoints -= amount;
    if(this->hitPoints < 0)
        this->hitPoints = 0;
    std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl;
    if(this->hitPoints <= 0)
    {
        std::cout << "ClapTrap " << name << " is dead!" << std::endl;
        return;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if(this->hitPoints <= 0)
    {
        std::cout << "ClapTrap " << name << " is dead!" << std::endl;
        return;
    }
    if(this->energyPoints == 0)
    {
        std::cout << "ClapTrap " << name << " has no energy points left!" << std::endl;
        return;
    }
    this->energyPoints -= 1;
    this->hitPoints += amount;
    std::cout << "ClapTrap " << name << " is repaired for " << amount << " points!" << std::endl;
}