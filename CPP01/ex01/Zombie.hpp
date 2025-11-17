/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:38:44 by skayed            #+#    #+#             */
/*   Updated: 2025/11/17 14:55:22 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <sstream>

class Zombie {
	
	private:
	
	std::string name;

	public:

	Zombie();
	~Zombie();
	void setName (std::string str);
	void Announce (void);
};

Zombie* zombieHorde( int N, std::string name );

#endif