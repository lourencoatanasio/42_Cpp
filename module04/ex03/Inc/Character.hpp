//
// Created by ldiogo on 1/15/24.
//

#ifndef INC_42_CPP_CHARACTER_HPP
#define INC_42_CPP_CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <iostream>

class Character : public ICharacter
{
private:
    std::string name;
    AMateria *inventory[4];
public:
    Character(std::string const &name);
    Character(const Character &character);
    ~Character();
    Character &operator=(const Character &character);

    std::string const &getName() const;
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
};


#endif //INC_42_CPP_CHARACTER_HPP
