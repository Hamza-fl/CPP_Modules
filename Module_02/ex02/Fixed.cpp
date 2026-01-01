/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalati <hfalati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 22:26:34 by hfalati           #+#    #+#             */
/*   Updated: 2025/10/17 20:57:23 by hfalati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fractional = 8;

Fixed::Fixed() : RawBits(0) {
}

Fixed::Fixed(const Fixed& other) {
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other)
        this->RawBits = other.RawBits;
    return *this;
}

Fixed::~Fixed() {}

Fixed::Fixed(const int value) {
    this->RawBits = value << fractional;
}

Fixed::Fixed(const float value) {
    this->RawBits = static_cast<int>(roundf(value * (1 << fractional)));
}

int Fixed::getRawBits(void) const {
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

bool Fixed::operator>(const Fixed& other) const { return RawBits > other.RawBits; }
bool Fixed::operator<(const Fixed& other) const { return RawBits < other.RawBits; }
bool Fixed::operator>=(const Fixed& other) const { return RawBits >= other.RawBits; }
bool Fixed::operator<=(const Fixed& other) const { return RawBits <= other.RawBits; }
bool Fixed::operator==(const Fixed& other) const { return RawBits == other.RawBits; }
bool Fixed::operator!=(const Fixed& other) const { return RawBits != other.RawBits; }

Fixed Fixed::operator+(const Fixed& other) const {
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const {
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const {
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const {
    return Fixed(this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++() {
    ++this->RawBits;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed tmp(*this);
    ++(*this);
    return tmp;
}

Fixed& Fixed::operator--() {
    --this->RawBits;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed tmp(*this);
    --(*this);
    return tmp;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return ((a < b) ? a : b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return ((a > b) ? a : b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return ((a > b) ? a : b);
}