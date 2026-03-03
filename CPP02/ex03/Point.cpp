/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 10:53:57 by skayed            #+#    #+#             */
/*   Updated: 2026/03/02 15:43:24 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0){}
Point::Point(float const x, float const y) : _x(x), _y(y){}
Point::Point(Point const &other): _x(other._x), _y(other._y){}

Point &Point::operator=(Point const &other){
	(void)other;
	return *this;
}
Point::~Point(){}
Fixed Point::getx() const{
	return(this->_x);
}
Fixed Point::gety() const{
	return(this->_y);
}