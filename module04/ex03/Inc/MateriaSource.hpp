//
// Created by rosal on 22/01/2024.
//

#ifndef MODULE04_MATERIASOURCE_HPP
#define MODULE04_MATERIASOURCE_HPP


#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include <iostream>

class MateriaSource : public IMateriaSource
{
private:
    AMateria *materia[4];
public:
    MateriaSource();
    MateriaSource(MateriaSource const &other);
    MateriaSource &operator=(MateriaSource const &other);
    ~MateriaSource();
    void learnMateria(AMateria*);
    AMateria* createMateria(std::string const & type);
};


#endif //MODULE04_MATERIASOURCE_HPP
