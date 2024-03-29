//
// Created by ldiogo on 1/15/24.
//

#include "../Inc/Ice.hpp"

Ice::Ice() : AMateria("ice")
{
    std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(const Ice &ice) : AMateria(ice)
{
}

Ice::~Ice()
{
}

Ice &Ice::operator=(const Ice &ice)
{
    if (this != &ice)
    {
        AMateria::operator=(ice);
    }
    return (*this);
}

AMateria *Ice::clone() const
{
    return (new Ice(*this));
}

void Ice::use(ICharacter &target)
{
    (void)target;
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
