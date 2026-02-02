#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base* generate(void)
{
    int random = rand() % 3;

    if (random == 0) {
        std::cout << "Generated: A" << std::endl;
        return new A();
    }
    else if (random == 1) {
        std::cout << "Generated: B" << std::endl;
        return new B();
    }
    else {
        std::cout << "Generated: C" << std::endl;
        return new C();
    }
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

void identify(Base& p)
{
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    }
    catch (std::exception&) {}
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    }
    catch (std::exception&) {}
    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    }
    catch (std::exception&) {}
}

int main()
{
    srand(time(NULL));
    
    Base* ptr1 = generate();
    std::cout << "Identify by pointer: ";
    identify(ptr1);
    std::cout << "Identify by reference: ";
    identify(*ptr1);
    delete ptr1;
    
    Base* ptr2 = generate();
    std::cout << "Identify by pointer: ";
    identify(ptr2);
    std::cout << "Identify by reference: ";
    identify(*ptr2);
    delete ptr2;
    
    return 0;
}