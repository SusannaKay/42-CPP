/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:54:10 by skayed            #+#    #+#             */
/*   Updated: 2026/02/26 16:04:30 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <cmath>
# include <iostream>

class Fixed
{
  private:
	int _rawBits;
	static const int _fractionalBits = 8;

  public:
	Fixed(void);
	Fixed(int const n);
	Fixed(float const n);
	Fixed(const Fixed &other);
	~Fixed();

	int getRawBits(void) const;
	void setRawBits(int const raw);

	float toFloat(void) const;
	int toInt(void) const;

	Fixed &operator=(const Fixed &other);

	bool operator>(const Fixed &other) const;
	bool operator<(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator==(const Fixed &other) const;
	bool operator!=(const Fixed &other) const;

	Fixed operator+(const Fixed &other) const;
	Fixed operator-(const Fixed &other) const;
	Fixed operator*(const Fixed &other) const;
	Fixed operator/(const Fixed &other) const;

	Fixed &operator++();   //pre-inc
	Fixed operator++(int); //post-inc
	Fixed &operator--();   //pre-dec
	Fixed operator--(int); //post-inc

	static const Fixed &min(const Fixed &n1, const Fixed &n2);
	static Fixed &min(Fixed &n1, Fixed &n2);
	static const Fixed &max(const Fixed &n1, const Fixed &n2);
	static Fixed &max(Fixed &n1, Fixed &n2);
};

std::ostream &operator<<(std::ostream &out, const Fixed &obj);

#endif