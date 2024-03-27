//
// Created by ldiogo on 3/25/24.
//

#include "../inc/Span.hpp"

Span::Span() : N(0) {}

Span::Span(unsigned int N) : N(N) {}

Span::Span(const Span &span) : N(span.N), numbers(span.numbers) {}

Span &Span::operator=(const Span &span) {
	if (this == &span)
		return *this;
	N = span.N;
	numbers = span.numbers;
	return *this;
}

Span::~Span() {}

void Span::addNumber(int n) {
	if (numbers.size() == N)
		throw SpanIsFull();
	numbers.push_back(n);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if (numbers.size() + std::distance(begin, end) > N)
		throw SpanIsFull();
	numbers.insert(numbers.end(), begin, end);
}

int Span::shortestSpan() {
	if (numbers.size() < 2)
		throw SpanIsShort();
	std::vector<int> sorted = numbers;
	std::sort(sorted.begin(), sorted.end());
	int min = INT_MAX;
	for (size_t i = 1; i < sorted.size(); i++) {
		int diff = sorted[i] - sorted[i - 1];
		if (diff < min)
			min = diff;
	}
	return min;
}

int Span::longestSpan() {
	int diff;
	if (numbers.size() < 2)
		throw SpanIsShort();
	std::vector<int> sorted = numbers;
	std::sort(sorted.begin(), sorted.end());
	diff = sorted[sorted.size() - 1] - sorted[0];
	if(diff < 0)
		diff *= -1;
	return diff;
}

int Span::getNumber(int i) const {
	if (i < 0 || i >= static_cast<int>(numbers.size()))
		throw SpanIsShort();
	return numbers[i];
}

