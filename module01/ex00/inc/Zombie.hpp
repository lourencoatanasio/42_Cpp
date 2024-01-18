#ifndef MODULE00_ZOMBIE_H
#define MODULE00_ZOMBIE_H

#include <iostream>

class Zombie
{
	private:
		std::string	name;
	public:
		Zombie(std::string name);
		~Zombie();
		void	announce();
};

Zombie* newZombie(std::string name);
void	randomChump(std::string name);

#endif //MODULE00_ZOMBIE_H
