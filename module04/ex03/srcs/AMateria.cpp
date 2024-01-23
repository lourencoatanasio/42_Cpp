//
// Created by ldiogo on 1/15/24.
//

#include "../Inc/AMateria.hpp"

AMateria::AMateria(const std::string &type)
{
    this->type = type;
}

AMateria::AMateria(const AMateria &other)
{
    *this = other;
}

AMateria::~AMateria()
{
}

AMateria &AMateria::operator=(const AMateria &other)
{
    this->type = other.type;
    return (*this);
}

const std::string &AMateria::getType() const
{
    return (this->type);
}

void AMateria::use(ICharacter &target)
{
    (void)target;
}
