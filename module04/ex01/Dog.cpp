//
// Created by ldiogo on 1/12/24.
//

#include "Dog.hpp"

Dog::Dog() : Animal()
{
    std::cout << "Dog default constructor called" << std::endl;
    this->type = "Dog";
    this->brain = new Brain();
}

Dog::Dog(Dog const &other) : Animal()
{
    std::cout << "Dog copy constructor called" << std::endl;
    this->brain = NULL;
    *this = other;
    std::cout << "Animal " << this->getType() << " copied." << std::endl;
}

Dog::~Dog()
{
    delete this->brain;
    std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(Dog const &other)
{
    std::cout << "Dog assignation operator called" << std::endl;
    if (this != &other)
    {
        type = other.type;
        if (this->brain)
            delete brain;
        this->brain = new Brain(*other.brain);
    }
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "Dog sound" << std::endl;
}
