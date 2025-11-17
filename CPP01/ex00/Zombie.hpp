/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:56:02 by skayed            #+#    #+#             */
/*   Updated: 2025/11/17 13:26:35 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie {
	
	private:
	
	std::string name;

	public:

	Zombie(std::string str);
	~Zombie();
	void Announce (void);
};

void randomChump( std::string name );
Zombie* newZombie( std::string name );

#endif