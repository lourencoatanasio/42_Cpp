//
// Created by ldiogo on 16-04-2024.
//

#ifndef INC_42_CPP_PMERGEME_HPP
#define INC_42_CPP_PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <exception>
#include <cstdlib>

class PmergeMe
{
    private:
        std::vector<int> numbers;
        std::vector<int> numbers1;
    public:
        PmergeMe();
        PmergeMe(char **argv);
        ~PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        static bool is_all_digit(const std::string &str);
        void merge();
        void mergeMe();
        void    print_numbers();
        void    swap(int &a, int &b);
        void    swapPairs(std::vector<int> &v);
        void    separate(std::vector<int> &v, std::vector<int> &v1, std::vector<int> &v2);
        size_t insertion_index(std::vector<int> &v, int target);
        class error : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};

long long jacobsthal(int n);


#endif //INC_42_CPP_PMERGEME_HPP
