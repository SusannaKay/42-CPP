/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 10:54:00 by skayed            #+#    #+#             */
/*   Updated: 2026/03/02 15:24:40 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point {
	private: 
	Fixed const _x;
	Fixed const _y;

	public:
	
	Point();
	Point(float const x, float const  y);
	Point(Point const &other);
	Point &operator=(Point const &other);
	~Point();

	Fixed getx() const;
	Fixed gety() const;
};

#endif