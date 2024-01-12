//
// Created by ldiogo on 1/12/24.
//

#ifndef INC_42_CPP_SCAVTRAP_HPP
#define INC_42_CPP_SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
    ScavTrap();
    ScavTrap(const std::string &name);
    ScavTrap(const ScavTrap &scavTrap);
    ScavTrap &operator=(const ScavTrap &scavTrap);
    ~ScavTrap();
    void attack(const std::string& target);
    void guardGate();
};


#endif //INC_42_CPP_SCAVTRAP_HPP
