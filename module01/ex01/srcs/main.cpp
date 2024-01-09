#include <iostream>
#include "../inc/main_header.hpp"

Zombie *zombieHorde(int N, std::string name)
{
	Zombie *zombie;

	zombie = new Zombie[N];
	for (int i = 0; i < N; i++)
		zombie[i].setName(name);
	return (zombie);
}

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
	int i;
	Zombie *zombie;

	zombie = zombieHorde(10, "Runners");
	i = 0;
	while (i < 10)
	{
		std::cout << i << " ";
		zombie[i].announce();
		i++;
	}
	i = 0;
	delete [] zombie;
	return (0);
}