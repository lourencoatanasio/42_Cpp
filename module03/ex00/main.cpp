#include "ClapTrap.hpp"

int main()
{
    ClapTrap clapTrap1("AmazingClapThatTraps");

    clapTrap1.attack("Some random dude");
    clapTrap1.takeDamage(9);
    clapTrap1.takeDamage(0);
    clapTrap1.beRepaired(10);
    for (int i = 0; i < 10; i++)
    {
        clapTrap1.beRepaired(10);
    }
    clapTrap1.takeDamage(10);
    clapTrap1.beRepaired(10);
}