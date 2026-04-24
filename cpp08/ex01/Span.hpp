#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <ctime>


class Span {
    private:
        unsigned int        maxSize;
        std::vector<int>    numbers;

    public:
        Span(unsigned int n);
        Span(const Span &other);
        Span &operator=(const Span &other);
        ~Span();

        void            addNumber(int n);
        int             shortestSpan() const;
        int             longestSpan() const;

        template<typename Iterator>void addRange(Iterator begin, Iterator end) {
            while (begin != end) {
                addNumber(*begin);
                ++begin;
            }
        }
};


#endif