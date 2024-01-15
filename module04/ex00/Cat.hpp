//
// Created by ldiogo on 1/15/24.
//

#ifndef INC_42_CPP_CAT_HPP
#define INC_42_CPP_CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
public:
    Cat();
    Cat(const Cat &other);
    ~Cat();
    Cat &operator=(const Cat &other);
    void makeSound() const;
};


#endif //INC_42_CPP_CAT_HPP
