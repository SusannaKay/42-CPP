/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 10:53:43 by skayed            #+#    #+#             */
/*   Updated: 2026/03/03 16:21:22 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed	check_point(Point const a, Point const b, Point const p)
{
	return ((b.getx() - a.getx()) * (p.gety() - a.gety()) - (b.gety()
			- a.gety()) * (p.getx() - a.getx()));
}
bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed d1(check_point(a, b, point));
	Fixed d2(check_point(b, c, point));
	Fixed d3(check_point(c, a, point));

	if (d1 < 0 && d2 < 0 && d3 < 0)
		return (true);
	if (d1 > 0 && d2 > 0 && d3 > 0)
		return (true);
	return (false);
}