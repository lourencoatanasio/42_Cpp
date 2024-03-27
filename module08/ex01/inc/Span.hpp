//
// Created by ldiogo on 3/25/24.
//

#ifndef INC_42_CPP_SPAN_HPP
#define INC_42_CPP_SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

class Span {
private:
	unsigned int N;
	std::vector<int> numbers;

public:
	Span();
	Span(unsigned int N);
	Span(const Span &span);
	Span &operator=(const Span &span);
	~Span();

	void addNumber(int n);
	void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	int shortestSpan();
	int longestSpan();
	int getNumber (int i) const;
	class SpanIsFull : public std::exception {
		virtual const char *what() const throw() {
			return "Span is full";
		}
	};
	class SpanIsShort : public std::exception {
		virtual const char *what() const throw() {
			return "Span has too few elements";
		}
	};
};


#endif //INC_42_CPP_SPAN_HPP
