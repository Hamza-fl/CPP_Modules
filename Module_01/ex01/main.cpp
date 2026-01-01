/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalati <hfalati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 16:33:43 by hfalati           #+#    #+#             */
/*   Updated: 2025/09/27 16:33:43 by hfalati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {

    int N = 5;
    Zombie* horde = zombieHorde(N, "HordeZombie");
    if (!horde)
        return 1;
    for (int i = 0; i < N; ++i)
        horde[i].announce();

    delete [] horde;
    return 0;
}
