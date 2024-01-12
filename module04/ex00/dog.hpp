//
// Created by ldiogo on 1/12/24.
//

#ifndef INC_42_CPP_DOG_HPP
#define INC_42_CPP_DOG_HPP


class dog : public Animal
{
    public:
        dog();
        dog(const dog &other);
        ~dog();
        dog &operator=(const dog &other);
        void makeSound() const;
};


#endif //INC_42_CPP_DOG_HPP
