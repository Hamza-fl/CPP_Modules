/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalati <hfalati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 16:33:50 by hfalati           #+#    #+#             */
/*   Updated: 2025/09/27 16:33:50 by hfalati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
private:
    std::string name;
public:
    Zombie();
    Zombie(const std::string& name);
    ~Zombie();

    void announce(void) const;
    void setName(const std::string& name);
};

Zombie* zombieHorde(int N, std::string name);

#endif