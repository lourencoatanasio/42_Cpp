//
// Created by rosal on 22/01/2024.
//

#include "../Inc/MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; ++i)
           this->materia[i] = NULL;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; ++i)
        delete this->materia[i];
}

MateriaSource::MateriaSource(const MateriaSource &materiaSource)
{
    *this = materiaSource;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &materiaSource)
{
    for (int i = 0; i < 4; ++i)
        this->materia[i] = materiaSource.materia[i];
    return (*this);
}

void MateriaSource::learnMateria(AMateria *m)
{
    for (int i = 0; i < 4; ++i)
        if (!this->materia[i])
        {
            this->materia[i] = m;
            return;
        }
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < 4; ++i)
        if (this->materia[i] && this->materia[i]->getType() == type)
            return (this->materia[i]->clone());
    return (NULL);
}

