/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalati <hfalati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 13:42:18 by hfalati           #+#    #+#             */
/*   Updated: 2025/10/23 09:47:01 by hfalati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main () {
    Point a(0.0f, 0.0f);
    Point b(10.0f, 0.0f);
    Point c(5.0f, 10.0f);
    
    Point inside(5.0f, 5.0f);
    Point outside(15.0f, 15.0f);
    Point onVertex(0.0f, 0.0f);
    Point onEdge(5.0f, 0.0f);
    
    std::cout << "Point (5, 5) inside triangle: " 
              << (bsp(a, b, c, inside) ? "true" : "false") << std::endl;
    
    std::cout << "Point (15, 15) inside triangle: " 
              << (bsp(a, b, c, outside) ? "true" : "false") << std::endl;
    
    std::cout << "Point on vertex (0, 0): " 
              << (bsp(a, b, c, onVertex) ? "true" : "false") << std::endl;
    
    std::cout << "Point on edge (5, 0): " 
              << (bsp(a, b, c, onEdge) ? "true" : "false") << std::endl;
    
    return 0;
}