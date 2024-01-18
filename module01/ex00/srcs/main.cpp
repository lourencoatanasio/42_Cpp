#include "../inc/Zombie.hpp"

int	main()
{
	Zombie *zombie;

	zombie = newZombie("Zombie 1");
	zombie->announce();
	randomChump("Zombie 2");
	delete zombie;
	return (0);
}