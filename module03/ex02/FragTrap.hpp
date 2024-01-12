//
// Created by ldiogo on 1/12/24.
//

#ifndef INC_42_CPP_FRAGTRAP_HPP
#define INC_42_CPP_FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
    FragTrap();
    FragTrap(const std::string &name);
    FragTrap(const FragTrap &fragTrap);
    FragTrap &operator=(const FragTrap &fragTrap);
    ~FragTrap();
    void highFivesGuys();
};


#endif //INC_42_CPP_FRAGTRAP_HPP
