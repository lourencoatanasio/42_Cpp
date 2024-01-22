//
// Created by ldiogo on 1/15/24.
//

#ifndef INC_42_CPP_CURE_HPP
#define INC_42_CPP_CURE_HPP

#include "AMateria.hpp"
#include <iostream>

class Cure : public AMateria
{
public:
    Cure();
    Cure(const Cure &cure);
    ~Cure();
    Cure &operator=(const Cure &cure);

    AMateria* clone() const;
    void use(ICharacter& target);
};


#endif //INC_42_CPP_CURE_HPP
