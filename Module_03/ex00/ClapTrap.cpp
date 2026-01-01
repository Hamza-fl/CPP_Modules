/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalati <hfalati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 13:03:23 by hfalati           #+#    #+#             */
/*   Updated: 2025/11/11 16:34:49 by hfalati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("anonymous"), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "Default constructor called for " << name << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap " << this->name << " constructed\n";
}

ClapTrap::ClapTrap(const ClapTrap& other) : name(other.name), hitPoints(other.hitPoints), energyPoints(other.energyPoints), attackDamage(other.attackDamage) {
	std::cout << "ClapTrap " << this->name << " copy-constructed\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	if (this != &other) {
		this->name = other.name;
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}
	std::cout << "ClapTrap " << this->name << " copy-assigned\n";
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << this->name << " destructed\n";
}

void ClapTrap::attack(const std::string& target) {
	if (hitPoints == 0) {
		std::cout << "ClapTrap " << name << " has no hit points.\n";
		return;
	}
	if (energyPoints == 0) {
		std::cout << "ClapTrap " << name << " has no energy.\n";
		return;
	}
	--energyPoints;
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage.\n";
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (hitPoints == 0) {
		std::cout << "ClapTrap " << name << " is already dead.\n";
		return;
	}
	if (amount >= hitPoints)
		hitPoints = 0;
	else
		hitPoints -= amount;
	std::cout << "ClapTrap " << name << " takes " << amount << " points of damage.\n";
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (hitPoints == 0) {
		std::cout << "ClapTrap " << name << " is dead.\n";
		return;
	}
	if (energyPoints == 0) {
		std::cout << "ClapTrap " << name << " has no energy.\n";
		return;
	}
	--energyPoints;
	hitPoints += amount;
	std::cout << "ClapTrap " << name << " is repaired by " << amount << " points.\n";
}