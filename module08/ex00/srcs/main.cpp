//
// Created by ldiogo on 3/25/24.
//

#include "../inc/easyfind.hpp"

template <typename T>
int easyfind(T &container, int value) {
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw std::exception();
	return *it;
}

int main() {
	std::vector<int> v;

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	try {
		std::cout << easyfind(v, 2) << std::endl;
		std::cout << easyfind(v, 4) << std::endl;
	} catch (std::exception &e) {
		std::cout << "Value not found" << std::endl;
	}

	std::list<int> l;

	l.push_back(1);
	l.push_back(2);
	l.push_back(3);

	try {
		std::cout << easyfind(l, 2) << std::endl;
		std::cout << easyfind(l, 4) << std::endl;
	} catch (std::exception &e) {
		std::cout << "Value not found" << std::endl;
	}

	std::deque<int> d;

	d.push_back(1);
	d.push_back(2);
	d.push_back(3);

	try {
		std::cout << easyfind(d, 2) << std::endl;
		std::cout << easyfind(d, 4) << std::endl;
	} catch (std::exception &e) {
		std::cout << "Value not found" << std::endl;
	}

	return 0;
}
