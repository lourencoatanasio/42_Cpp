//
// Created by ldiogo on 3/25/24.
//

#ifndef INC_42_CPP_SPAN_HPP
#define INC_42_CPP_SPAN_HPP


class Span {
public:
	Span(unsigned int n);
	Span(const Span &span);
	Span &operator=(const Span &span);
	~Span();

	void addNumber(int n);
	int shortestSpan();
	int longestSpan();
};


#endif //INC_42_CPP_SPAN_HPP
