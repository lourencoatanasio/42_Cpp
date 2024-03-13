//
// Created by ldiogo on 3/13/24.
//

#ifndef INC_42_CPP_BASE_HPP
#define INC_42_CPP_BASE_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

class Base {
public:
	virtual ~Base();
};

class A : public Base {

};

class B : public Base {

};

class C : public Base {

};

void	identify_from_pointer(Base *p);
void	identify_from_reference(Base &p);
Base	*generate(void);


#endif //INC_42_CPP_BASE_HPP
