//
// Created by ldiogo on 1/15/24.
//

#include "Cat.hpp"

Cat::Cat() : Animal()
{
    std::cout << "Cat default constructor called" << std::endl;
    type = "Cat";
    this->brain = new Brain();
}

Cat::Cat(Cat const &other) : Animal()
{
    std::cout << "Cat copy constructor called" << std::endl;
    this->brain = NULL;
    *this = other;
    std::cout << "Animal " << this->getType() << " copied." << std::endl;
}
Cat::~Cat()
{
    delete this->brain;
    std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(Cat const &other)
{
    std::cout << "Cat assignation operator called" << std::endl;
    if (this != &other)
    {
        type = other.type;
        if (this->brain)
            delete brain;
        this->brain = new Brain(*other.brain);
    }
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "Cat sound" << std::endl;
}
