#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <list>
#include <deque>

// Lambda function to roll a die
auto roll = []() { return rand() % 6 + 1; };

int main()
{
    // Create container
    std::vector<int> container;
    // to test list
    // std::list<int> container;
    // to test deque
    // std::deque<int> container;

    // Add 1 item
    container.push_back(roll());
    const int* pAddressOfOriginalItemZero = &(*container.begin());

    std::chrono::duration<double> durInsertTime(0);

    do
    {
        // Get Address of first item
        const int* pAddressOfItemZero = &(*container.begin());

        std::cout << "Contains " << container.size()
                  << " elements, took "
                  << std::chrono::duration_cast<std::chrono::microseconds>(durInsertTime).count()
                  << "us\n";

        for (const auto& i : container)
        {
            const int* pAddressOfItemX = &i;

            int pItemOffset = pAddressOfItemX - pAddressOfItemZero;
            int pItemOffsetOriginal = pAddressOfItemX - pAddressOfOriginalItemZero;

            std::cout << "Offset From Original: " << pItemOffsetOriginal
                      << " Offset From Zero: " << pItemOffset
                      << " : Content: " << i << "\n";
        }

        auto tp1 = std::chrono::high_resolution_clock::now();
        container.push_back(roll());
        auto tp2 = std::chrono::high_resolution_clock::now();

        durInsertTime = (tp2 - tp1);

    } while (getc(stdin)); // press any key to continue

    return 0;
}