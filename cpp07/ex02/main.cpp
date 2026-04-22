#include "Array.hpp"

int main(void)
{
    Array<int> arr(5);

    for (unsigned int i = 0; i < arr.size(); i++)
        arr[i] = i * 10;

    std::cout << "Array content:" << std::endl;
    for (unsigned int i = 0; i < arr.size(); i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    Array<int> copy(arr);
    copy[0] = 999;

    std::cout << "Original first element: " << arr[0] << std::endl;
    std::cout << "Copy first element: " << copy[0] << std::endl;

    try {
        std::cout << arr[10] << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    const Array<int> cst(arr);
    std::cout << cst[2] << std::endl;

    return 0;
}