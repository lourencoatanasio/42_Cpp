//
// Created by ldiogo on 1/15/24.
//

#ifndef INC_42_CPP_BRAIN_HPP
#define INC_42_CPP_BRAIN_HPP

#include <iostream>

class Brain
{
    private:
        std::string ideas[100];
    public:
        Brain();
        ~Brain();
        Brain(Brain const &other);
        Brain &operator=(Brain const &other);
};


#endif //INC_42_CPP_BRAIN_HPP
