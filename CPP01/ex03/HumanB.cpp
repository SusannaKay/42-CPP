/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:33:20 by skayed            #+#    #+#             */
/*   Updated: 2025/11/20 16:10:23 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

	
HumanB::HumanB(std::string str): name(str), weapon(NULL) {
	
}
HumanB::~HumanB(){
	
}
void HumanB::attack(){
	
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon& w){
	weapon = &w;
}