/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 16:25:42 by skayed            #+#    #+#             */
/*   Updated: 2026/01/02 16:33:08 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed{

	private: 
	int fixed_point;
	static const int fractionalBits;


	public:
	Fixed();
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(int const raw);
}

#endif