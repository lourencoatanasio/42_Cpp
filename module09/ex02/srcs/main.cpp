//
// Created by ldiogo on 16-04-2024.
//

#include "../inc/PmergeMe.hpp"

long long jacobsthal(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

long long getTimeMs() {
    timeval currentTime;
    gettimeofday(&currentTime, NULL);
    return currentTime.tv_sec * 1000000 + currentTime.tv_usec;
}


int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Error: no arguments" << std::endl;
        return 1;
    }
    try
    {
        PmergeMe pmergeMe(argv);
        pmergeMe.N = getTimeMs();
        std::cout << "Before: ";
        pmergeMe.print_numbers();
        pmergeMe.mergeMeV();
        std::cout << "After: ";
        pmergeMe.print_numbers();
        std::cout << "Time to process a range with " << pmergeMe.get_size() << " elements with std::vector:    " << getTimeMs() - pmergeMe.N << " us." << std::endl;
        pmergeMe.N = getTimeMs();
        pmergeMe.mergeMeDQ();
        std::cout << "Time to process a range with " << pmergeMe.get_size() << " elements with std::deque:    " << getTimeMs() - pmergeMe.N << " us." << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}