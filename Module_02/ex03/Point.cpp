/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalati <hfalati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 13:46:18 by hfalati           #+#    #+#             */
/*   Updated: 2025/10/23 09:20:12 by hfalati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const float x, const float y) : x(x), y(y) {}

Point::Point(const Point &other) : x(other.x), y(other.y) {}

Point &Point::operator=(const Point &other) {
    (void)other;
    return *this;
}

Point::~Point() {}

Fixed Point::getX() const {
    return this->x;
}

Fixed Point::getY() const {
    return this->y;
}