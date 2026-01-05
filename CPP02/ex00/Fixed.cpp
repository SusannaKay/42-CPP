/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 16:26:03 by skayed            #+#    #+#             */
/*   Updated: 2026/01/05 15:04:11 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

	Fixed::Fixed(){
		std::cout << "Default constructor called" << std::endl;
		setRawBits(0);
	}

	Fixed::Fixed(const Fixed& other){
		std::cout << "Copy constructor called" << std::endl;
		*this = other;		
	}
	
	Fixed& Fixed::operator=(const Fixed& other){
		std::cout << "Copy assignment operator called" << std::endl;
		_rawBits = other.getRawBits();
		return *this;
	}
	
	Fixed::~Fixed(){
		std::cout <<"Destructor called"<< std::endl;
	}
	
	int Fixed::getRawBits(void) const{
		std::cout << "getRawBits member function called"<< std::endl;
		return this->_rawBits;
	}
	
	void Fixed::setRawBits(int const raw){
		_rawBits = raw;
	}