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
#include <cmath>
#include <sys/time.h>

class PmergeMe
{
    private:
        std::vector<int> numbers;
        std::vector<int> numbers1;
        std::deque<int> dq;
        std::deque<int> dq1;
    public:
        long long N;
        PmergeMe();
        PmergeMe(char **argv);
        ~PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        static bool is_all_digit(const std::string &str);
        void mergeV();
        void mergeDQ();
        void mergeMeV();
        void mergeMeDQ();
        void    print_numbers();
        void    swap(int &a, int &b);
        int get_size();

        template<typename T>
        void    swapPairs(T &container, size_t size);

        template<typename T>
        void    separate(T &container, T &container1, T &container2);

        template <typename T>
        size_t insertion_index(T &container, int target);

        class error : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};

long long jacobsthal(int n);
long long getTimeMs();


#endif //INC_42_CPP_PMERGEME_HPP
