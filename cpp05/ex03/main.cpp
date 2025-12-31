#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    std::cout << "=== Test Shrubbery ===" << std::endl;
    {
        Bureaucrat bob("Bob", 137);
        ShrubberyCreationForm shrub("home");
        
        bob.signForm(shrub);
        bob.executeForm(shrub);
    }

    std::cout << "\n=== Test Robotomy ===" << std::endl;
    {
        Bureaucrat alice("Alice", 45);
        RobotomyRequestForm robot("Bender");
        
        alice.signForm(robot);
        alice.executeForm(robot);
    }

    std::cout << "\n=== Test Presidential ===" << std::endl;
    {
        Bureaucrat president("President", 1);
        PresidentialPardonForm pardon("Arthur");
        
        president.signForm(pardon);
        president.executeForm(pardon);
    }

    return 0;
}