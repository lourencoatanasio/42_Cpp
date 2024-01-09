#ifndef MODULE00_ZOMBIE_H
#define MODULE00_ZOMBIE_H

#include <iostream>

class Zombie
{
	private:
		std::string	name;
	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();
		void	announce();
		void	setName(std::string name);
};

#endif //MODULE00_ZOMBIE_H
