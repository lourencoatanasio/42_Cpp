#include "../inc/Zombie.hpp"

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