#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {

    try
    {
        Bureaucrat bob("Bob", 137);
        ShrubberyCreationForm shrub("home");
        
        bob.signForm(shrub);
        bob.executeForm(shrub);
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << '\n';
    }
    try {
        Bureaucrat alice("Alice", 45);
        RobotomyRequestForm robot("Bender");
        
        alice.signForm(robot);
        alice.executeForm(robot);
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << '\n';
    }
    try {
        Bureaucrat president("President", 1);
        PresidentialPardonForm pardon("Arthur");
        
        president.signForm(pardon);
        president.executeForm(pardon);
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << '\n';
    }

    return 0;
}