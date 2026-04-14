#include "iter.hpp"

template <typename T> void print(T const &elem) {
    std::cout << elem << std::endl;
}

int main(void)
{
    int arr[] = {1, 2, 3, 4, 5};
    ::iter(arr, 5, print<int>);

    const int arr2[] = {10, 20, 30};
    ::iter(arr2, 3, print<int>);

    std::string words[] = {"hello", "world", "42"};
    ::iter(words, 3, print<std::string>);

    return 0;
}