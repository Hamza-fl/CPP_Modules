/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalati <hfalati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 11:44:58 by hfalati           #+#    #+#             */
/*   Updated: 2025/09/23 15:01:25 by hfalati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
    if (ac >= 2) {
        for (int i = 1; av[i]; i++) {
            for (int j = 0; av[i][j]; j++) {
                std::cout << (char)(std::toupper((av[i][j])));
            }
        }
    } else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    std::cout << std::endl;
    return 0;
}
