/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:07:42 by skayed            #+#    #+#             */
/*   Updated: 2026/02/23 14:30:53 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Constructor & Destructor Functions

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	setRawBits(0);
}

Fixed::Fixed(int const n)
{
	std::cout << "Int constructor called" << std::endl;
	this->_rawBits = n << this->_fractionalBits;
}

Fixed::Fixed(float const n)
{
	std::cout << "Float constructor called" << std::endl;
	this->_rawBits = roundf(n * (1 << this->_fractionalBits));
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	_rawBits = other.getRawBits();
	return (*this);
}

// Set & Get Functions
int Fixed::getRawBits(void) const
{
	return (this->_rawBits);
}

void Fixed::setRawBits(int const raw)
{
	this->_rawBits = raw;
}

// Conversion Functions
float Fixed::toFloat(void) const
{
	return ((float)this->_rawBits / (1 << this->_fractionalBits));
}
int Fixed::toInt(void) const
{
	return (this->_rawBits >> this->_fractionalBits);
}

//Extra class
std::ostream &operator<<(std::ostream &out, Fixed const &obj)
{
	out << obj.toFloat();
	return (out);
};