/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalati <hfalati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 16:46:44 by hfalati           #+#    #+#             */
/*   Updated: 2025/11/11 17:39:25 by hfalati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    {
        ClapTrap a("Alpha");
        a.attack("a rock");
        a.takeDamage(5);
        a.beRepaired(3);
    }
    {
        ScavTrap s1("Serena");
        s1.attack("an enemy");
        s1.guardGate();
    }

    return 0;
}