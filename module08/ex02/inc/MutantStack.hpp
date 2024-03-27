//
// Created by ldiogo on 27-03-2024.
//

#ifndef INC_42_CPP_MUTANTSTACK_HPP
#define INC_42_CPP_MUTANTSTACK_HPP

#include <stack>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack() : std::stack<T>() {}
	MutantStack(MutantStack const &src) : std::stack<T>(src) {}
	MutantStack &operator=(MutantStack const &rhs)
	{
		if (this != &rhs)
			std::stack<T>::operator=(rhs);
		return *this;
	}
	~MutantStack() {}
	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator begin() { return std::stack<T>::c.begin(); }
	iterator end() { return std::stack<T>::c.end(); }
};


#endif //INC_42_CPP_MUTANTSTACK_HPP
