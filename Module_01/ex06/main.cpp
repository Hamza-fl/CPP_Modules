/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalati <hfalati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 16:35:40 by hfalati           #+#    #+#             */
/*   Updated: 2025/09/27 16:35:41 by hfalati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main (int ac, char **av)
{
    if (ac != 2){
        std::cout << "usage: .harlfilter <level>\n";
        return 1;
    }
    Harl harl;
    harl.complain(std::string(av[1]));
    return 0;
}