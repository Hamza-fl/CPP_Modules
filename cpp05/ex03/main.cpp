#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    std::cout << "=== Testing Intern ===" << std::endl;
    
    Intern intern;
    Bureaucrat boss("Boss", 1);
    
    // Test 1: Create robotomy request
    std::cout << "\n--- Test 1: Robotomy Request ---" << std::endl;
    AForm* form1 = intern.makeForm("robotomy request", "Bender");
    if (form1) {
        boss.signForm(*form1);
        boss.executeForm(*form1);
        delete form1;
    }
    
    // Test 2: Create shrubbery creation
    std::cout << "\n--- Test 2: Shrubbery Creation ---" << std::endl;
    AForm* form2 = intern.makeForm("shrubbery creation", "home");
    if (form2) {
        boss.signForm(*form2);
        boss.executeForm(*form2);
        delete form2;
    }
    
    // Test 3: Create presidential pardon
    std::cout << "\n--- Test 3: Presidential Pardon ---" << std::endl;
    AForm* form3 = intern.makeForm("presidential pardon", "Arthur");
    if (form3) {
        boss.signForm(*form3);
        boss.executeForm(*form3);
        delete form3;
    }
    return 0;
}