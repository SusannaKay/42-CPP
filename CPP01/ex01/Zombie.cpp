/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:38:39 by skayed            #+#    #+#             */
/*   Updated: 2025/11/26 16:06:26 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(){

	std::cout << "Zombie Created" << std::endl;
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

