#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    
    try {

        Intern intern;
        Bureaucrat boss("Boss", 1);
        
        try {
            AForm* form1 = intern.makeForm("robotomy request", "Bender");
            boss.signForm(*form1);
            boss.executeForm(*form1);
            delete form1;
        }
        catch (std::exception& e) {
            std::cout << "Exception caught: " << e.what() << '\n';
        }

        try {

            AForm* form2 = intern.makeForm("shrubbery creation", "home");
            boss.signForm(*form2);
            boss.executeForm(*form2);
            delete form2;
        }
        catch (std::exception& e) {
            std::cout << "Exception caught: " << e.what() << '\n';
        }

        try {
            AForm* form3 = intern.makeForm("presidential pardon", "Arthur");
            boss.signForm(*form3);
            boss.executeForm(*form3);
            delete form3;
        }
        catch (std::exception& e) {
            std::cout << "Exception caught: " << e.what() << '\n';
        }
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << '\n';
    }
    return 0;
}