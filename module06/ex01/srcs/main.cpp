//
// Created by ldiogo on 3/13/24.
//

#include "Serializer.hpp"

int main()
{
	Data data;
	data.data = 42;
	data.data2 = 24;

	std::cout << "Data: " << data.data << " " << data.data2 << std::endl;

	uintptr_t raw = Serializer::serialize(&data);

	std::cout << "Raw: " << raw << std::endl;

	Data *ptr = Serializer::deserialize(raw);

	std::cout << "Data: " << ptr->data << " " << ptr->data2 << std::endl;

	return 0;
}