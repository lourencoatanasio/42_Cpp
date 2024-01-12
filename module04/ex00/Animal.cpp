//
// Created by ldiogo on 1/12/24.
//

#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal &other)
{
    std::cout << "Animal copy constructor called" << std::endl;
    type = other.type;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
    std::cout << "Animal assignation operator called" << std::endl;
    if (this != &other)
        type = other.type;
    return (*this);
}

void Animal::makeSound() const
{
    std::cout << "Animal sound" << std::endl;
}