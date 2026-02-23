/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:07:10 by skayed            #+#    #+#             */
/*   Updated: 2026/02/23 14:09:28 by skayed           ###   ########.fr       */
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
	Fixed &operator=(const Fixed &other);
	~Fixed();
	
	int getRawBits(void) const;
	void setRawBits(int const raw);
	
	float toFloat(void) const;
	int toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &obj);

#endif
