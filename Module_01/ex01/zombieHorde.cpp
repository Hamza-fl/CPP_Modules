/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalati <hfalati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 16:33:55 by hfalati           #+#    #+#             */
/*   Updated: 2025/09/27 16:33:55 by hfalati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {

    if (N <= 0)
        return NULL;

    Zombie* horde = new Zombie[N];
    if (!horde)
        return nullptr;
    for (int i = 0; i < N; ++i)
        horde[i].setName(name);
    return horde;
}
