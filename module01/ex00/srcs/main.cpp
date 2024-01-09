#include <iostream>
#include "../inc/main_header.hpp"

Zombie *newZombie(std::string name)
{
	Zombie *zombie;

	zombie = new Zombie(name);
	return (zombie);
}

void	randomChump(std::string name)
{
	Zombie zombie(name);

	zombie.announce();
}

int	main()
{
	Zombie *zombie;

	zombie = newZombie("Zombie 1");
	zombie->announce();
	randomChump("Zombie 2");
	delete zombie;
	return (0);
}