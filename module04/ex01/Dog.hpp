//
// Created by ldiogo on 1/12/24.
//

#ifndef INC_42_CPP_DOG_HPP
#define INC_42_CPP_DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
    Brain *brain;
public:
    Dog();
    Dog(const Dog &other);
    ~Dog();
    Dog &operator=(const Dog &other);
    void makeSound() const;
};


#endif //INC_42_CPP_DOG_HPP
