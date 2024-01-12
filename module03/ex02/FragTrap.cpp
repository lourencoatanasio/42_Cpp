//
// Created by ldiogo on 1/12/24.
//

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "FragTrap constructor called" << std::endl;
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
    this->name = "FragTrap";
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
    std::cout << "FragTrap constructor called" << std::endl;
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &fragTrap) : ClapTrap(fragTrap)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
    *this = fragTrap;
}

FragTrap &FragTrap::operator=(const FragTrap &fragTrap)
{
    std::cout << "FragTrap assignation operator called" << std::endl;
    if (this != &fragTrap)
    {
        this->hitPoints = fragTrap.hitPoints;
        this->energyPoints = fragTrap.energyPoints;
        this->attackDamage = fragTrap.attackDamage;
        this->name = fragTrap.name;
    }
    return *this;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "High fives guys! * expects high five *" << std::endl;
}
