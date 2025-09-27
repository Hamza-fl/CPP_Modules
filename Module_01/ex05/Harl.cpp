#include "Harl.hpp"

Harl::Harl () {}
Harl::~Harl () {}

void Harl::debug () {
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n";
}

void Harl::info () {
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}


void Harl::warning(void) {
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month.\n";
}

void Harl::error(void) {
    std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

// pointer to function --> void(*<name>)(); --> typedef void (*<name>)(); and use the <name> to call it

void Harl::complain(std::string level) {
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    typedef void (Harl::*ptr_fn) (void);
    ptr_fn functions[4];
    functions[0] = &Harl::debug;
    functions[1] = &Harl::info;
    functions[2] = &Harl::warning;
    functions[3] = &Harl::error;

    for (int i = 0; i < 4; i++) {
        if (levels[i] == level)
        {
            (this->*functions[i])();
            return;
        }
    }
}