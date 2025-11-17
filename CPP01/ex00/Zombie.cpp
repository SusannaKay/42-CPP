/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:08:30 by skayed            #+#    #+#             */
/*   Updated: 2025/11/17 12:31:54 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string str) : name(str){
}
Zombie::~Zombie(){
		std::cout << name << ": Destroyed" << std::endl;
}
void Zombie::Announce (void){
	
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}