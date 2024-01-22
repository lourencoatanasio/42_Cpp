//
// Created by rosal on 22/01/2024.
//

#ifndef MODULE04_IMATERIASOURCE_HPP
#define MODULE04_IMATERIASOURCE_HPP

#include<iostream>
#include"AMateria.hpp"

class IMateriaSource
{
public:
    virtual ~IMateriaSource() {}
    virtual void learnMateria(AMateria*) = 0;
    virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif //MODULE04_IMATERIASOURCE_HPP
