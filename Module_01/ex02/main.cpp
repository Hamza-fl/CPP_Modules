/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalati <hfalati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 16:33:58 by hfalati           #+#    #+#             */
/*   Updated: 2025/09/27 16:33:58 by hfalati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main() {
    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string& stringREF = str;
    std::cout << "Address of string:   " << &str << std::endl;
    std::cout << "Address held by PTR: " << stringPTR << std::endl;
    std::cout << "Address of REF:      " << &stringREF << std::endl;
    std::cout << "Value of string:     " << str << std::endl;
    std::cout << "Value pointed by PTR:" << *stringPTR << std::endl;
    std::cout << "Value of REF:        " << stringREF << std::endl;
    return 0;
}