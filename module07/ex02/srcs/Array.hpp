//
// Created by ldiogo on 3/21/24.
//

#ifndef INC_42_CPP_ARRAY_HPP
#define INC_42_CPP_ARRAY_HPP

#include <stdexcept>
#include <iostream>
#include <string>

template <typename T>
class Array {
public:
	Array() : array(NULL), size(0) {}
	Array(unsigned int n) : size(n) {
		array = new T[n];
	}
	Array(const Array &other) {
		size = other.size;
		array = new T[size];
		for (unsigned int i = 0; i < size; i++) {
			array[i] = other.array[i];
		}
	}
	~Array() {
		delete [] array;
	}
	Array &operator=(const Array &other) {
		if (this != &other) {
			delete [] array;
			size = other.size;
			array = new T[size];
			for (unsigned int i = 0; i < size; i++) {
				array[i] = other.array[i];
			}
		}
		return *this;
	}
	T &operator[](unsigned int i) {
		if (i >= size) {
			throw std::out_of_range("Index out of bounds");
		}
		return array[i];
	}
	unsigned int getSize() const {
		return size;
	}
	// std::exception
	const char *what() const throw() {
		return "Index out of bounds";
	}
private:
	T *array;
	unsigned int size;
};


#endif //INC_42_CPP_ARRAY_HPP
