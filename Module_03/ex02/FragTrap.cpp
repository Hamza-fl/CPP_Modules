/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalati <hfalati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:13:32 by hfalati           #+#    #+#             */
/*   Updated: 2025/11/11 17:35:55 by hfalati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	std::cout << "FragTrap default constructor called\n";
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
    std::cout << "FragTrap " << this->name << " constructor called\n";
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
}


FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    std::cout << "FragTrap copy constructor called\n";
    this->hitPoints = other.hitPoints;
    this->energyPoints = other.energyPoints;
    this->attackDamage = other.attackDamage;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    std::cout << "FragTrap assignment operator called\n";
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap destructor called for " << this->name << std::endl;
}

void FragTrap::attack(const std::string& target) {
    if (hitPoints == 0) {
        std::cout << "FragTrap " << name << " has no hit points.\n";
        return;
    }
    if (energyPoints == 0) {
        std::cout << "FragTrap " << name << " has no energy.\n";
        return;
    }
    --energyPoints;
    std::cout << "FragTrap " << name << " launches a powerful attack on " << target << ", dealing " << attackDamage << " points of damage!\n";
}

void FragTrap::highFivesGuys() {
    if (hitPoints == 0) {
        std::cout << "FragTrap " << name << " is dead and cannot high five.\n";
        return;
    }
    std::cout << "FragTrap " << name << " requests a positive high five!\n";
}