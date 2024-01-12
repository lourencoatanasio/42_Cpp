//
// Created by ldiogo on 1/12/24.
//

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    std::cout << "ScavTrap constructor called" << std::endl;
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    this->name = "ScavTrap";
}

ScavTrap::ScavTrap(const std::string &name)
{
    std::cout << "ScavTrap constructor called" << std::endl;
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    this->name = name;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &scavTrap) : ClapTrap(scavTrap)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
    *this = scavTrap;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scavTrap)
{
    std::cout << "ScavTrap assignation operator called" << std::endl;
    if (this != &scavTrap)
    {
        this->hitPoints = scavTrap.hitPoints;
        this->energyPoints = scavTrap.energyPoints;
        this->attackDamage = scavTrap.attackDamage;
        this->name = scavTrap.name;
    }
    return *this;
}

void ScavTrap::attack(const std::string &target)
{
    if (this->hitPoints < 1)
    {
        std::cout << this->name << " is dead" << std::endl;
        return;
    }
    if (this->energyPoints < 1)
    {
        std::cout << this->name << " is out of energy" << std::endl;
        return;
    }
    std::cout << this->name << " attacks " << target << ", causing a whooping " << this->attackDamage << " points of damage!" << std::endl;
    this->energyPoints -= 1;
}

void ScavTrap::guardGate()
{
    std::cout << this->name << " has entered in Gate keeper mode" << std::endl;
}
