/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 10:53:54 by skayed            #+#    #+#             */
/*   Updated: 2026/03/03 16:18:48 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point); 

int main(void)
{
	Point a(0.f, 0.f);
	Point b(10.f, 0.f);
	Point c(0.f, 10.f);

	Point p1(1.f, 1.f);   // dentro
	Point p2(10.f, 10.f); // fuori
	Point p3(0.f, 5.f);   // bordo -> fuori

	std::cout << bsp(a, b, c, p1) << "\n";
	std::cout << bsp(a, b, c, p2) << "\n";
	std::cout << bsp(a, b, c, p3) << "\n";
}