/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalati <hfalati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 16:33:24 by hfalati           #+#    #+#             */
/*   Updated: 2025/09/27 16:33:24 by hfalati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    Zombie* z1 = newZombie("HeapZombie");
    if (!z1)
    {
        std::cerr << "failed to allocate memory\n";
        return 1;
    }
    z1->announce();
    delete z1;

    randomChump("StackZombie");

    return 0;
}