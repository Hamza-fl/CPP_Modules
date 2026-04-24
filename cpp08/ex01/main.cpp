#include "Span.hpp"

int main()
{
    // --- Test from the subject ---
    std::cout << "=== Subject test ===" << std::endl;
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl; // expected: 2
    std::cout << sp.longestSpan() << std::endl;  // expected: 14

    // --- Test exception: span full ---
    std::cout << "\n=== Full span test ===" << std::endl;
    try {
        sp.addNumber(99);
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // --- Test exception: too few numbers ---
    std::cout << "\n=== Too few numbers test ===" << std::endl;
    Span sp2(1);
    sp2.addNumber(42);
    try {
        std::cout << sp2.shortestSpan() << std::endl;
    } catch (std::exception &e) {
        std::cout << "shortestSpan exception: " << e.what() << std::endl;
    }
    try {
        std::cout << sp2.longestSpan() << std::endl;
    } catch (std::exception &e) {
        std::cout << "longestSpan exception: " << e.what() << std::endl;
    }

    // --- Test addRange with 10,000 numbers ---
    std::cout << "\n=== Large range test (10,000 numbers) ===" << std::endl;
    Span sp3(10000);
    std::vector<int> bigVec;
    std::srand(std::time(0));
    for (int i = 0; i < 10000; i++)
        bigVec.push_back(std::rand());
    sp3.addRange(bigVec.begin(), bigVec.end());
    std::cout << "Shortest span: " << sp3.shortestSpan() << std::endl;
    std::cout << "Longest span:  " << sp3.longestSpan() << std::endl;

    // --- Test addRange overflow ---
    std::cout << "\n=== addRange overflow test ===" << std::endl;
    Span sp4(5);
    try {
        sp4.addRange(bigVec.begin(), bigVec.end());
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}