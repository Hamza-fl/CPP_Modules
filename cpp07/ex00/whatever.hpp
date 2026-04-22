#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template<typename T>void swap(T &v1, T &v2) {
    T temp = v1;
    v1= v2;
    v2 = temp;
}

template<typename T>T min(T const &v1, T const &v2) {
    return (v1 < v2) ? v1 : v2;
}

template<typename T>T max(T const &v1, T const &v2) {
    return (v1 > v2) ? v1 : v2;
}

#endif