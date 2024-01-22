//
// Created by ldiogo on 1/15/24.
//

#ifndef INC_42_CPP_ICE_HPP
#define INC_42_CPP_ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

class Ice : public AMateria
{
public:
    Ice();
    Ice(const Ice &ice);
    ~Ice();
    Ice &operator=(const Ice &ice);

    AMateria* clone() const;
    void use(ICharacter& target);
};


#endif //INC_42_CPP_ICE_HPP
