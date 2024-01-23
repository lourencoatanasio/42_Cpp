//
// Created by ldiogo on 1/15/24.
//

#ifndef INC_42_CPP_AMATERIA_HPP
#define INC_42_CPP_AMATERIA_HPP

#include <string>
#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
protected:
    std::string type;
public:
    AMateria(std::string const & type);
    AMateria(AMateria const & other);
    virtual ~AMateria();
    AMateria & operator=(AMateria const & other);

    std::string const & getType() const;
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};


#endif //INC_42_CPP_AMATERIA_HPP
