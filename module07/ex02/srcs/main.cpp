//
// Created by ldiogo on 3/21/24.
//

#include "../inc/Array.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>

#define MAX_VAL 10000
int main(int, char**)
{
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++) // fill the array with random numbers
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}

	{ // create a scope
		Array<int> tmp = numbers;
		Array<int> test(tmp);
		for (int i = 0; i < MAX_VAL; i++) // check if the copy constructor works
		{
			if (tmp[i] != mirror[i])
			{
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}
	}

	for (int i = 0; i < MAX_VAL; i++) // check if the values are still the same
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try // try to access an element out of the limits
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try // try to access an element in limits
	{
		numbers[MAX_VAL - 1] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++) 	// fill the array with random numbers
	{
		numbers[i] = rand();
	}
	delete [] mirror;
	return 0;
}