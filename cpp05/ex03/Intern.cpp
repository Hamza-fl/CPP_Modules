
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {}

Intern::Intern(Intern const & other) {
    *this = other;
}

Intern & Intern::operator=(Intern const & other) {
    (void)other;
    return *this;
}

Intern::~Intern() {}

AForm* createShrubbery(std::string target) {
    return new ShrubberyCreationForm(target);
}

AForm* createRobotomy(std::string target) {
    return new RobotomyRequestForm(target);
}

AForm* createPardon(std::string target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string formName, std::string target) {

    std::string formTypes[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    AForm* (*creators[3])(std::string) = {
        &createShrubbery,
        &createRobotomy,
        &createPardon
    };
    for (int i = 0; i < 3; i++) {
        if (formTypes[i] == formName) {
            std::cout << "Intern creates " << formName << std::endl;
            return creators[i](target);
        }
    }
    std::cout << "Error: Form '" << formName << "' does not exist" << std::endl;
    return NULL;
}