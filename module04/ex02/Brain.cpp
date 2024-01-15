#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain was created" << std::endl;
    for(int i = 0; i < 100; i++)
        this->ideas[i] = "Ideas";
}

Brain::~Brain()
{
    std::cout << "Brain was destroyed" << std::endl;
}

Brain::Brain(Brain const &other)
{
    std::cout << "Brain copy constructor called" << std::endl;
    *this = other;
}

Brain &Brain::operator=(Brain const &other)
{
    std::cout << "Brain operator used" << std::endl;
    if (this != &other)
    {
        for(int i = 0; i < 100; i++)
            this->ideas[i] = other.ideas[i];
    }
    return *this;
}