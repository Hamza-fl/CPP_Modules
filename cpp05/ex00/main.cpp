/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalati <hfalati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 10:25:32 by hfalati           #+#    #+#             */
/*   Updated: 2025/11/21 10:37:39 by hfalati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat a("Alice", 2);
        std::cout << a;

        a.increment();
        std::cout << a;
        try {
            a.increment();
        } catch (std::exception& e) {
            std::cout << "Exception caught: " << e.what() << '\n';
        }
        try {
            Bureaucrat tooHigh("TooHigh", 0);
        } catch (std::exception& e) {
            std::cout << "Construction exception: " << e.what() << '\n';
        }

        try {
            Bureaucrat tooLow("TooLow", 151);
        } catch (std::exception& e) {
            std::cout << "Construction exception: " << e.what() << '\n';
        }
        Bureaucrat b("Bob", 150);
        std::cout << b;
        try {
            b.decrement(); }
        catch (std::exception& e) {
            std::cout << "Exception caught: " << e.what() << '\n';
        }
    }
    catch (std::exception& e)
    {
        std::cerr << "Unhandled exception: " << e.what() << '\n';
    }
    return 0;
}