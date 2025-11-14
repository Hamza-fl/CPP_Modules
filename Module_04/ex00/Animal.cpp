/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalati <hfalati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 11:35:10 by hfalati           #+#    #+#             */
/*   Updated: 2025/11/14 14:44:13 by hfalati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("") {
    std::cout << "Animal default constructor called\n";
}

Animal::Animal(const Animal& other) : type(other.type) {
    std::cout << "Animal copy constructor called\n";
}

Animal& Animal::operator=(const Animal& other) {
    if (this != &other) {
        type = other.type;
    }
    std::cout << "Animal copy assignment operator called\n";
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal destructor called\n";
}

void Animal::makeSound() const {
    std::cout << "Generic animal sound\n";
}

std::string Animal::getType() const {
    return type;
}