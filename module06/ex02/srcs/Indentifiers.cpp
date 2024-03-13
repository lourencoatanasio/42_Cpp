//
// Created by ldiogo on 3/13/24.
//

#include "../inc/Classes.hpp"

Base::~Base()
{
}

void	identify_from_pointer(Base *p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void	identify_from_reference(Base &p) {
	identify_from_pointer(&p);
}

Base	*generate(void)
{
	srand(time(NULL) ^ (getpid() << 16));
	int		r = rand() % 3;

	if (r == 0)
	{
		std::cout << "Generated an A" << std::endl;
		return new A;
	}
	else if (r == 1)
	{
		std::cout << "Generated a B" << std::endl;
		return new B;
	}
	else
	{
		std::cout << "Generated a C" << std::endl;
		return new C;
	}
}
