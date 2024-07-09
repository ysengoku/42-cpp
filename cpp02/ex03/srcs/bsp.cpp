/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 11:03:41 by yusengok          #+#    #+#             */
/*   Updated: 2024/07/09 11:03:43 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "../includes/Fixed.hpp"

Fixed calculateArea(Point const p1, Point const p2, Point const p3)
{
    Fixed area;
	Fixed p1X = p1.getX();
	Fixed p1Y = p1.getY();
	Fixed p2X = p2.getX();
	Fixed p2Y = p2.getY();
	Fixed p3X = p3.getX();
	Fixed p3Y = p3.getY();
	
	area = (((p2X - p1X) * (p3Y - p1Y)) - ((p2Y - p1Y) * (p3X - p1X))) \
	* Fixed(0.5f);
    if (area < Fixed(0))
        area = area * Fixed(-1);
    return area;
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	if (a == b || a == c || b == c || a == point || b == point || c == point)
		return (false);
	Fixed	totalArea = calculateArea(a, b, c);
	Fixed	area1 = calculateArea(a, b, point);
	Fixed	area2 = calculateArea(a, c, point);
	Fixed	area3 = calculateArea(b, c, point);
	Fixed	zero(0);
	if (area1 == zero || area2 == zero || area3 == zero || totalArea == zero)
		return (false);
	return (totalArea == (area1 + area2 + area3));
}
