/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalati <hfalati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 21:25:27 by hfalati           #+#    #+#             */
/*   Updated: 2025/10/16 22:23:16 by hfalati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fractional = 8;

Fixed::Fixed() : RawBits(0) {
    std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called\n";
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called\n";
    if (this != &other)
        this->RawBits = other.RawBits;
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called\n";
}

Fixed::Fixed(const int value) {
    std::cout << "Int constructor called\n";
    this->RawBits = value << fractional;
}

Fixed::Fixed(const float value) {
    std::cout << "Float constructor called\n";
    this->RawBits = static_cast<int>(roundf(value * (1 << fractional)));
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called\n";
    return this->RawBits;
}

void Fixed::setRawBits(int const raw) {
    this->RawBits = raw;
}

int Fixed::toInt(void) const {
    return this->RawBits >> fractional;
}

float Fixed::toFloat(void) const {
    return static_cast<float>(this->RawBits) / static_cast<float>(1 << fractional);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}