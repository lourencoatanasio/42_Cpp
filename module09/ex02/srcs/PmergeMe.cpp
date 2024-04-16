//
// Created by ldiogo on 16-04-2024.
//

#include "../inc/PmergeMe.hpp"

void    PmergeMe::print_numbers()
{
    std::cout << "numbers: ";
    for (size_t i = 0; i < numbers.size(); i++)
    {
        std::cout << numbers[i];
        if (i + 1 < numbers.size())
        {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
    for (size_t i = 0; i < numbers1.size(); i++)
    {
        std::cout << numbers1[i];
        if (i + 1 < numbers1.size())
        {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}

void    PmergeMe::swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void    PmergeMe::swapPairs(std::vector<int> &v)
{
    for (size_t i = 0; i < v.size() - 2; i++)
    {
        if (i % 2 == 0)
        {
            if(v[i + 1] > v[i + 3])
            {
                swap(v[i], v[i + 2]);
                swap(v[i + 1], v[i + 3]);
                i = -1;
            }
        }
    }
}

bool    PmergeMe::is_all_digit(const std::string &str) {
    for (size_t i = 0; i < str.size(); i++)
    {
        if (!std::isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

void    PmergeMe::separate(std::vector<int> &v, std::vector<int> &v1, std::vector<int> &v2)
{
    for(size_t i = 0; i < v.size(); i++)
    {
        if(i % 2 != 0)
            v1.push_back(v[i]);
        else
            v2.push_back(v[i]);
    }
    v = v1;
}

void    PmergeMe::merge()
{
    std::cout << "Before merge: ";
    print_numbers();
    int numbers_size = numbers.size();
    int jacob_order = 2;
    int smaller_index = 0;
    int index;

    std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
    std::cout << std::endl;
    while (numbers.size() < numbers1.size() + numbers_size)
    {
        index = jacobsthal(jacob_order) - 1;
        std::cout << "index: " << index << std::endl;
        size_t insertion = insertion_index(this->numbers, this->numbers1[index]);
        std::cout << "insertion: " << insertion << std::endl;
        numbers.insert(this->numbers.begin() + insertion, this->numbers1[index]);
        index--;
        while (index > smaller_index)
        {
            std::cout << "index: " << index << std::endl;
            size_t insertion = insertion_index(this->numbers, this->numbers1[index]);
            std::cout << "insertion: " << insertion << std::endl;
            numbers.insert(this->numbers.begin() + insertion, this->numbers1[index]);
            print_numbers();
            std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
            index--;
        }
        smaller_index = jacobsthal(jacob_order) - 1;
        print_numbers();
        std::cout << "smaller_index: " << smaller_index << std::endl;
        std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
        jacob_order++;
    }
    std::cout << std::endl << "After merge: ";
    print_numbers();
}

size_t PmergeMe::insertion_index(std::vector<int> &v, int target)
{
    size_t low = 0;
    size_t high = v.size() - 1;

    for(size_t i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "target: " << target << std::endl;
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (v[mid] == target)
            return mid;
        else if (v[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}

void    PmergeMe::mergeMe()
{
    std::cout << "Before mergeMe: ";
    print_numbers();
    for(size_t i = 0; i < numbers.size(); i++)
    {
        if(i % 2 != 0)
        {
            if(numbers[i] < numbers[i - 1])
                swap(numbers[i], numbers[i - 1]);
        }
    }
    swapPairs(numbers);
    std::vector<int> tmp;
    separate(numbers, tmp, numbers1);
    merge();
    std::cout << std::endl << "After merge: ";
    print_numbers();
}

PmergeMe::PmergeMe()
{
    std::cout << "PmergeMe created" << std::endl;
}

PmergeMe::PmergeMe(char **argv)
{
    for (int i = 1; argv[i]; i++)
    {
        if (!is_all_digit(argv[i]))
        {
            throw std::invalid_argument("Invalid argument : " + std::string(argv[i]));
        }
        numbers.push_back(std::atoi(argv[i]));
    }
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
    (void)other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    (void)other;
    return *this;
}
