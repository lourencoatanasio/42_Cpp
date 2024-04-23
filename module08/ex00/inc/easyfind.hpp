//
// Created by ldiogo on 3/25/24.
//

#ifndef INC_42_CPP_EASYFIND_HPP
#define INC_42_CPP_EASYFIND_HPP

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <deque>

template <typename T>
int easyfind(T &container, int value) {
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw std::exception();
    return *it;
}

#endif //INC_42_CPP_EASYFIND_HPP
