//
// Created by ldiogo on 3/13/24.
//

#include "../inc/Classes.hpp"

int main() {
	Base	*ptr;

	ptr = generate();
	identify_from_pointer(ptr);
	identify_from_reference(*ptr);
	delete ptr;
	ptr = generate();
	identify_from_pointer(ptr);
	identify_from_reference(*ptr);
	delete ptr;
	ptr = generate();
	identify_from_pointer(ptr);
	identify_from_reference(*ptr);
	delete ptr;
	return 0;
}
