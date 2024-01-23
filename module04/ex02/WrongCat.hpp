//
// Created by ldiogo on 1/15/24.
//

#ifndef INC_42_CPP_WRONGCAT_HPP
#define INC_42_CPP_WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
    WrongCat();
    WrongCat(const WrongCat &other);
    ~WrongCat();
    WrongCat &operator=(const WrongCat &other);

    void makeSound() const;
};


#endif //INC_42_CPP_WRONGCAT_HPP
