#include "../inc/HumanB.hpp"

HumanB :: HumanB(std::string name) : weapon(0)
{
	this->name = name;
}

HumanB :: ~HumanB()
{
}

void	HumanB :: attack()
{
    if(weapon == 0)
        std::cout << name << " has no weapon" << std::endl;
    else
	    std::cout << name << " attacks with his " << weapon->getType() << std::endl;
}

void	HumanB :: setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}
