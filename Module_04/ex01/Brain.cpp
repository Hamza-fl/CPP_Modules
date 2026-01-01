/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalati <hfalati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:39:22 by hfalati           #+#    #+#             */
/*   Updated: 2025/11/14 15:41:27 by hfalati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"


Brain::Brain() {
    for (int i = 0; i < 100; ++i) ideas[i] = "";
    std::cout << "Brain default constructor called\n";
}
Brain::Brain(const Brain& other) {
    for (int i = 0; i < 100; ++i)
        ideas[i] = other.ideas[i];
    std::cout << "Brain copy constructor called\n";
}
Brain& Brain::operator=(const Brain& other) {
    if (this != &other) {
        for (int i = 0; i < 100; ++i) ideas[i] = other.ideas[i];
    }
    std::cout << "Brain copy assignment operator called\n";
    return *this;
}
Brain::~Brain() {
    std::cout << "Brain: destructor called\n";
}

void Brain::setIdea(int idx, const std::string& idea) {
    if (idx >= 0 && idx < 100)
        ideas[idx] = idea;
}
std::string Brain::getIdea(int idx) const {
    if (idx >= 0 && idx < 100)
        return ideas[idx];
    return "";
}