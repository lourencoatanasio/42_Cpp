//
// Created by ldiogo on 16-04-2024.
//

#include "../inc/PmergeMe.hpp"

void    PmergeMe::print_numbers()
{
    for (size_t i = 0; i < numbers.size(); i++)
    {
        std::cout << numbers[i];
        if (i + 1 < numbers.size())
        {
            std::cout << " ";
        }
        if(i > 3)
        {
            std::cout << "[...]";
            break;
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

int PmergeMe::get_size()
{
    return numbers.size();
}

template <typename T>
void PmergeMe::swapPairs(T &container, size_t size)
{
    if (size >= container.size())
        return ;
    for (size_t i = 1; i < container.size() - 1; i += 2)
    {
        if (container[i] > container[size])
        {
            std::swap(container[i], container[size]);
            std::swap(container[i - 1], container[size - 1]);
        }
    }
    swapPairs(container, size + 2);
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

template <typename T>
void PmergeMe::separate(T &container, T &container1, T &container2)
{
    for(size_t i = 0; i < container.size(); i++)
    {
        if(i % 2 != 0)
            container1.push_back(container[i]);
        else
            container2.push_back(container[i]);
    }
    container = container1;
}

void    PmergeMe::mergeV()
{
    int numbers_size = numbers.size();
    int jacob_order = 2;
    int smaller_index = 0;
    int index;

    while (numbers.size() < numbers1.size() + numbers_size)
    {
        index = jacobsthal(jacob_order) - 1;
        if(index > (int)numbers1.size() - 1)
            index = numbers1.size() - 1;
        size_t insertion = insertion_index(this->numbers, this->numbers1[index]);
        numbers.insert(this->numbers.begin() + insertion, this->numbers1[index]);
        index--;
        while (index > smaller_index)
        {
            size_t insertion = insertion_index(this->numbers, this->numbers1[index]);
            numbers.insert(this->numbers.begin() + insertion, this->numbers1[index]);
            index--;
        }
        smaller_index = jacobsthal(jacob_order) - 1;
        jacob_order++;
    }
}

void    PmergeMe::mergeDQ()
{
    int numbers_size = dq.size();
    int jacob_order = 2;
    int smaller_index = 0;
    int index;

    while (dq.size() < dq1.size() + numbers_size)
    {
        index = jacobsthal(jacob_order) - 1;
        if(index > (int)dq1.size() - 1)
            index = dq1.size() - 1;
        size_t insertion = insertion_index(this->dq, this->dq1[index]);
        dq.insert(this->dq.begin() + insertion, this->dq1[index]);
        index--;
        while (index > smaller_index)
        {
            size_t insertion = insertion_index(this->dq, this->dq1[index]);
            dq.insert(this->dq.begin() + insertion, this->dq1[index]);
            index--;
        }
        smaller_index = jacobsthal(jacob_order) - 1;
        jacob_order++;
    }
}

template <typename T>
size_t PmergeMe::insertion_index(T &container, int target)
{
    int low = 0;
    int high = container.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (container[mid] == target)
            return mid;
        else if (container[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}

void    PmergeMe::mergeMeDQ()
{
    int odd = 0;
    for(size_t i = 0; i < dq.size(); i++)
    {
        if(i % 2 != 0)
        {
            if(dq[i] < dq[i - 1])
                swap(dq[i], dq[i - 1]);
        }
    }
    if(dq.size() % 2 != 0)
    {
        odd = dq[dq.size() - 1];
        dq.pop_back();
    }
    swapPairs(dq, 1);
    std::deque<int> tmp;
    separate(dq, tmp, dq1);
    if(odd != 0)
        dq1.push_back(odd);
    mergeDQ();
}

void    PmergeMe::mergeMeV()
{
    int odd = 0;
    for(size_t i = 0; i < numbers.size(); i++)
    {
        if(i % 2 != 0)
        {
            if(numbers[i] < numbers[i - 1])
                swap(numbers[i], numbers[i - 1]);
        }
    }
    if(numbers.size() % 2 != 0)
    {
        odd = numbers[numbers.size() - 1];
        numbers.pop_back();
    }
    swapPairs(numbers, 1);
    std::vector<int> tmp;
    separate(numbers, tmp, numbers1);
    if(odd != 0)
        numbers1.push_back(odd);
    mergeV();
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
        dq.push_back(std::atoi(argv[i]));
    }
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &other) : numbers(other.numbers), numbers1(other.numbers1), dq(other.dq), dq1(other.dq1)
{
    (void)other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if(this != &other)
    {
        numbers = other.numbers;
        numbers1 = other.numbers1;
        dq = other.dq;
        dq1 = other.dq1;
    }
    return *this;
}
