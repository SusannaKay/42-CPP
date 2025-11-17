/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:38:39 by skayed            #+#    #+#             */
/*   Updated: 2025/11/17 14:16:54 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(){
}
Zombie::~Zombie(){
		std::cout << name << ": Destroyed" << std::endl;
}
void Zombie::setName (std::string str){
	name = str;
}
void Zombie::Announce (void){
	
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

