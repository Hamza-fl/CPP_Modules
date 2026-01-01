/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalati <hfalati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 13:46:25 by hfalati           #+#    #+#             */
/*   Updated: 2025/10/23 09:49:20 by hfalati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed area(Point const a, Point const b, Point const c) {
    Fixed area = ((a.getX() * (b.getY() - c.getY())) +
                  (b.getX() * (c.getY() - a.getY())) +
                  (c.getX() * (a.getY() - b.getY()))) / 2;
    if (area < 0)
        return (area * -1);
    return area;
}

bool bsp( Point const a, Point const b, Point const c, Point const point) {
    Fixed mainArea = area(a, b , c);
    
    if (mainArea == 0)
        return false;
    
    Fixed area1 = area(point, b, c);
    Fixed area2 = area(a, point, c);
    Fixed area3 = area(a, b, point);

    if (area1 == 0 || area2 == 0 || area3 == 0)
        return false;

    return (area1 + area2 + area3) == mainArea;
}