#include "../inc/Zombie.hpp"

void	Zombie::announce()
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout << name << " is dead" << std::endl;
}

Zombie::Zombie(std::string name)
{
	this->name = name;
}

Zombie::Zombie()
{
	this->name = "";
}


