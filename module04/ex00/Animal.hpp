//
// Created by ldiogo on 1/12/24.
//

#ifndef INC_42_CPP_ANIMAL_HPP
#define INC_42_CPP_ANIMAL_HPP


class Animal
{
    protected:
        std::string type;
    public:
        Animal();
        Animal(const Animal &other);
        ~Animal();
        Animal &operator=(const Animal &other);
        virtual void makeSound() const;
        std::string getType() const;
};


#endif //INC_42_CPP_ANIMAL_HPP
