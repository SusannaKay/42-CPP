/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 12:14:32 by skayed            #+#    #+#             */
/*   Updated: 2025/11/25 13:03:30 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
class Harl{

	public:
	void complain(std::string level);
	
	private:
	
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
};



#endif