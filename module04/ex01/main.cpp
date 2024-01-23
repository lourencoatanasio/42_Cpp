#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    Animal **animais = new Animal *[6];
    for (int i = 0; i < 3; i++)
    {
        std::cout << "Dog #" << i + 1 << "============" << std::endl;
        animais[i] = new Dog();
    }
    std::cout << std::endl;
    for (int i = 3; i < 6; i++)
    {
        std::cout << "Cat #" << i - 2 << "============" << std::endl;
        animais[i] = new Cat();
    }
    std::cout << std::endl;
    for (int i = 0; i < 6; i++)
    {
        std::cout << "Deletion #" << i + 1 << "============" << std::endl;
        delete animais[i];
    }
    delete[] animais;
    std::cout << std::endl;

    Dog cao1;
    {
        std::cout << std::endl;
        Dog cao2 = cao1;
    }
    std::cout << std::endl;
    return 0;
}