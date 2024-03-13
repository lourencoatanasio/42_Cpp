//
// Created by ldiogo on 3/13/24.
//

#ifndef INC_42_CPP_SERIALIZER_HPP
#define INC_42_CPP_SERIALIZER_HPP

#include "../inc/Data.hpp"
#include <stdint.h>
#include <iostream>

class Serializer {
private:
	Serializer();
	~Serializer();
	Serializer(const Serializer &other);
	Serializer &operator=(const Serializer &other);
public:
	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);
};


#endif //INC_42_CPP_SERIALIZER_HPP
