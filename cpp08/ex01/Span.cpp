#include "Span.hpp"

Span::Span(unsigned int n) : maxSize(n) {}

Span::Span(const Span &other) : maxSize(other.maxSize), numbers(other.numbers) {}

Span &Span::operator=(const Span &other) {
    if (this != &other) {
        maxSize = other.maxSize;
        numbers = other.numbers;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int n) {
    if (numbers.size() >= maxSize)
        throw std::runtime_error("Span if full");
    numbers.push_back(n);
}

int Span::longestSpan() const {
    if (numbers.size() < 2)
        throw std::runtime_error("Not enough numbers to find a span");
    
    int min = *std::min_element(numbers.begin(), numbers.end());
    int max = *std::max_element(numbers.begin(), numbers.end());
    return max - min;
}

int Span::shortestSpan() const {
    if (numbers.size() < 2)
        throw std::runtime_error("Not enough numbers to find a span");
    std::vector<int> sorted(numbers);
    std::sort(sorted.begin(), sorted.end());
    int shortest = sorted[1] - sorted[0];
    int tmp;
    for (size_t i = 1; i < sorted.size() - 1; i++) {
        tmp = sorted[i + 1] - sorted[i];
        if (tmp < shortest)
            shortest = tmp;
    }
    return shortest;

}