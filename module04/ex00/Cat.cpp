//
// Created by ldiogo on 1/15/24.
//

#include "Cat.hpp"

Cat::Cat() : Animal()
{
    std::cout << "cat default constructor called" << std::endl;
    type = "Cat";
}

Cat::Cat(const Cat &other) : Animal(other)
{
    std::cout << "Cat copy constructor called" << std::endl;
    type = other.type;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
    std::cout << "Cat assignation operator called" << std::endl;
    if (this != &other)
        type = other.type;
    return (*this);
}

void Cat::makeSound() const
{
    std::cout << "Cat sound" << std::endl;
}
