/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:48:46 by skayed            #+#    #+#             */
/*   Updated: 2025/11/20 14:30:19 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
	
HumanA::HumanA(std::string str, Weapon& w): name(str), weapon(w) {
	
}
HumanA::~HumanA(){
	
}
void HumanA::attack(){
	
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}