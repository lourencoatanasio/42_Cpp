//
// Created by ldiogo on 3/21/24.
//

#include <iostream>
#include <cctype>

template <typename T>
void iter(T *array, size_t size, void (*f)(T &))
{
	for (size_t i = 0; i < size; i++)
	{
		f(array[i]);
	}
}

void convertToUpper(char &c)
{
	c = toupper(c);
}

void multiplyByTwo(int &n)
{
	n *= 2;
}

int main()
{
	// Test with integers
	{
		int array[] = {1, 2, 3, 4, 5};
		iter(array, 5, multiplyByTwo);
		for (int i = 0; i < 5; i++)
		{
			std::cout << array[i] << " ";
		}
		std::cout << std::endl;
	}
	// Test with characters
	{
		char str[] = "Hello";
		iter(str, 5, convertToUpper);
		std::cout << str << std::endl;
	}
	return 0;
}