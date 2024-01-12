#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ClapTrap clapTrap1("AmazingClapThatTraps");

    clapTrap1.attack("Some random dude");
    clapTrap1.takeDamage(9);
    clapTrap1.takeDamage(0);
    clapTrap1.beRepaired(10);
    for (int i = 0; i < 3; i++)
    {
        clapTrap1.beRepaired(10);
    }
    clapTrap1.takeDamage(100);

    ScavTrap scavTrap1("AmazingScavThatTraps");

    scavTrap1.attack("Some other random dude");
    scavTrap1.takeDamage(98);
    scavTrap1.takeDamage(1);
    scavTrap1.beRepaired(100);
    for (int i = 0; i < 3; i++)
    {
        std::cout << i << ": ";
        scavTrap1.beRepaired(100);
    }
    scavTrap1.takeDamage(100);

    scavTrap1.guardGate();
}