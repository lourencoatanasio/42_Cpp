//
// Created by ldiogo on 27-03-2024.
//

#include "../inc/Span.hpp"
#include <ctime>

int main() {
	try { // This will work
		std::srand(static_cast<unsigned int>(std::time(NULL)));
		std::vector<int> v;
		for (int i = 0; i < 1000; i++) {
			v.push_back(std::rand() % std::rand() % std::rand() * (std::rand() % 2 ? 1 : -1));
		}
		std::srand(static_cast<unsigned int>(std::time(NULL)));
		Span span(1000000000);
		span.addNumber(v.begin(), v.end());
		std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
		std::cout << "Longest span: " << span.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try { // This will throw an exception
		std::srand(static_cast<unsigned int>(std::time(NULL)));
		Span span(1000);
		for (int i = 0; i < 10000; i++) {
			span.addNumber(std::rand() % std::rand() % std::rand() * (std::rand() % 2 ? 1 : -1));
		}
		std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
		std::cout << "Longest span: " << span.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Span sp = Span(5);
		sp.addNumber(6);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}