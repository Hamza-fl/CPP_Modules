#include "Array.hpp"

int main(void)
{
    Array<int> empty;
    std::cout << "empty size = " << empty.size() << std::endl;

    Array<int> arr(5);
    for (unsigned int i = 0; i < arr.size(); i++)
        arr[i] = (int)(i * 10);
    for (unsigned int i = 0; i < arr.size(); i++)
        std::cout << "arr[" << i << "] = " << arr[i] << std::endl;

    Array<int> copy(arr);
    copy[0] = 999;
    std::cout << "arr[0] = " << arr[0] << " (should be 0)" << std::endl;
    std::cout << "copy[0] = " << copy[0] << " (should be 999)" << std::endl;

    Array<int> assigned;
    assigned = arr;
    assigned[1] = 777;
    std::cout << "arr[1] = " << arr[1] << " (should be 10)" << std::endl;
    std::cout << "assigned[1] = " << assigned[1] << " (should be 777)" << std::endl;

    try {
        arr[10] = 42;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    const Array<int> cst(arr);
    std::cout << "cst[2] = " << cst[2] << std::endl;

    return 0;
}