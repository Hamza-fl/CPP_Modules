/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalati <hfalati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 10:25:32 by hfalati           #+#    #+#             */
/*   Updated: 2025/12/30 17:00:20 by hfalati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main()
{
	std::cout << "TEST 1: Form creation" << std::endl;
	Form f("SimpleForm", 50, 30);
	std::cout << f << std::endl;

	std::cout << "\nTEST 2: Successful signing" << std::endl;
	Bureaucrat good("Alice", 40);
	good.signForm(f);
	std::cout << f << std::endl;

	std::cout << "\nTEST 3: Failed signing" << std::endl;
	Bureaucrat bad("Bob", 100);
	Form f2("HardForm", 20, 10);
	bad.signForm(f2);

	return 0;
}