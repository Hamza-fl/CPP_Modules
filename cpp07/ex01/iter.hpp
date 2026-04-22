#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T, typename F>void iter(T *array, size_t const len, F func) {
    size_t i = 0;
    while (i < len) {
        func(array[i]);
            i++;
    }
}

#endif