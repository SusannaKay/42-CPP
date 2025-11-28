/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HarlFilter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 12:14:32 by skayed            #+#    #+#             */
/*   Updated: 2025/11/28 09:47:12 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARLFILTER_HPP
#define HARLFILTER_HPP

#include <iostream>
class Harl{

	public:
	void complain(int i);
	
	private:
	
	Harl();
	~Harl();
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
};



#endif