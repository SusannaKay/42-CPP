/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:31:55 by skayed            #+#    #+#             */
/*   Updated: 2025/11/20 14:18:42 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string str): type(str){
	
}

Weapon::~Weapon(){
	
}
const std::string& Weapon::getType() const{
	return this->type;
}

void Weapon::setType(std::string str){
	type = str;
}