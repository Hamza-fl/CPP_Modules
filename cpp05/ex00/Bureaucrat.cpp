/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalati <hfalati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 10:25:27 by hfalati           #+#    #+#             */
/*   Updated: 2025/12/30 15:29:00 by hfalati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& n, int g) : name(n), grade(g) {
    if (g < 1)
        throw Bureaucrat::GradeTooHighException();
    if (g > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other) {
        this->grade = other.grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string& Bureaucrat::getName() const {
    return name;
}

int Bureaucrat::getGrade() const {
    return grade;
}

void Bureaucrat::increment() {
    if (grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    --grade;
}

void Bureaucrat::decrement() {
    if (grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    ++grade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "GradeTooHighException";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "GradeTooLowException";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".\n";
    return os;
}