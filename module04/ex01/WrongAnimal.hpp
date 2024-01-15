//
// Created by ldiogo on 1/15/24.
//

#ifndef INC_42_CPP_WRONGANIMAL_HPP
#define INC_42_CPP_WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
protected:
        std::string type;
    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal &other);
        virtual ~WrongAnimal();
        WrongAnimal &operator=(const WrongAnimal &other);
        void makeSound() const;
        std::string getType() const;
};


#endif //INC_42_CPP_WRONGANIMAL_HPP
