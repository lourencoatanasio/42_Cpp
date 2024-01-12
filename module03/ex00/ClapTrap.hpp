//
// Created by ldiogo on 1/12/24.
//

#ifndef INC_42_CPP_CLAPTRAP_H
#define INC_42_CPP_CLAPTRAP_H

#include <iostream>
#include <string>

class ClapTrap
{
protected:
    const std::string name;
    int hitPoints;
    int energyPoints;
    int attackDamage;
public:
    ClapTrap(const std::string &name);
    ~ClapTrap();
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};


#endif //INC_42_CPP_CLAPTRAP_H
