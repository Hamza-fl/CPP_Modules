/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalati <hfalati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 16:47:17 by hfalati           #+#    #+#             */
/*   Updated: 2025/11/11 17:04:54 by hfalati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
    std::cout << "ScavTrap default constructor called\n";
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
    std::cout << "ScavTrap " << name << " constructor called\n";
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    std::cout << "ScavTrap copy constructor called\n";
    this->hitPoints = other.hitPoints;
    this->energyPoints = other.energyPoints;
    this->attackDamage = other.attackDamage;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    std::cout << "ScavTrap assignment operator called\n";
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap destructor called\n";
}

void ScavTrap::attack(const std::string& target) {
    if (hitPoints == 0) {
        std::cout << "ScavTrap " << name << " has no hit points.\n";
        return;
    }
    if (energyPoints == 0) {
        std::cout << "ScavTrap " << name << " has no energy.\n";
        return;
    }
    --energyPoints;
    std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!\n";
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << name << " is now in Gate keeper mode.\n";
}